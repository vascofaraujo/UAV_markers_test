#include "opencv2\opencv.hpp"
using namespace cv;

#include <time.h>
#include <ctime>
#include <math.h>



cv::Mat four_point_transform(cv::Mat gray, std::vector< Point2f > Candidate) {
	double widthA, widthB, maxWidth, heightA, heightB, maxHeight;
	cv::Mat M, warped;
	widthA = sqrt(pow((Candidate[2].x - Candidate[3].x), 2.0) + pow((Candidate[2].y - Candidate[3].y), 2.0));
	widthB = sqrt(pow((Candidate[1].x - Candidate[0].x), 2.0) + pow((Candidate[1].y - Candidate[0].y), 2.0));
	maxWidth = max(int(widthA), int(widthB));

	heightA = sqrt(pow((Candidate[1].x - Candidate[2].x), 2.0) + pow((Candidate[1].y - Candidate[2].y), 2.0));
	heightB = sqrt(pow((Candidate[0].x - Candidate[3].x), 2.0) + pow((Candidate[0].y - Candidate[3].y), 2.0));
	maxHeight = max(int(heightA), int(heightB));


		std::vector< Point2f > dst;
		dst.resize(4);
		dst[0] = Point2f((float)0, (float)0);
		dst[1] = Point2f((float)(maxWidth - 1), (float)(0));
		dst[2] = Point2f((float)(maxWidth - 1), (float)(maxHeight - 1));
		dst[3] = Point2f((float)(0), (float)(maxHeight - 1));

			M = getPerspectiveTransform(Candidate, dst);
			warpPerspective(gray, warped,M, cv::Size(int(maxWidth), int(maxHeight)));

			return warped;
}


bool compare_distance(std::vector< Point > cnt) {
	float p12, p23, p34, p41, minimum_dist, maximum_dist;
	bool result;

	p12 = sqrt(pow(cnt[0].x - cnt[1].x, 2) + pow(cnt[0].y - cnt[1].y, 2));
	p23 = sqrt(pow(cnt[1].x - cnt[2].x, 2) + pow(cnt[1].y - cnt[2].y, 2));
	p34 = sqrt(pow(cnt[2].x - cnt[3].x, 2) + pow(cnt[2].y - cnt[3].y, 2));
	p41 = sqrt(pow(cnt[0].x - cnt[3].x, 2) + pow(cnt[0].y - cnt[3].y, 2));
	
	minimum_dist = min(p12, p23);
	minimum_dist = min(minimum_dist, p34);
	minimum_dist = min(minimum_dist, p41);

	maximum_dist = max(p12, p23);
	maximum_dist = max(maximum_dist, p34);
	maximum_dist = max(maximum_dist, p41);

	if (minimum_dist / maximum_dist > 0.4)
		result = true;
	else
		result = false;

	
	return result;
}


std::vector< std::vector< Point2f > > match_warped(std::vector< std::vector< Point2f > > candidates, cv::Mat gray, std::vector <cv::Mat> warpedCandidates) {
	std::vector< std::vector< Point2f > > markers;
	cv::Mat patch;
	cv::Size sz;
	int patchWidth;
	int patchHeight;
	int white, black, npixel;
	uchar pixel;
		
	for (unsigned int i = 0; i < candidates.size(); i++) {
		patch = warpedCandidates[i];
		sz = patch.size();
		patchWidth = sz.width;
		patchHeight = sz.height;
		//std::cout << "NEW PATCH" << patch << "\n";
		white = 0;
		black = 1;
		npixel = 0;
		for (int h = round(patchHeight*0.4); h < round(patchHeight * 0.6); h++) {
			for (int w = round(patchWidth * 0.4); w < round(patchWidth * 0.6); w++) {
				//std::cout << "W:" << w << " WIDTH:" << patchWidth  << "\n H:" << h << "HEIGHT" << patchHeight <<"\n";
				//std::cout << "NUMPIXEIS" << npixel << "\n";
				npixel++;
				pixel = warpedCandidates[i].at<uchar>(h, w);
				//std::cout << "Pixel!" << pixel <<"\n";
				if (pixel == 255)
					white++;
				else black++;
			}
		}


		if (float(black) / float(white) < 0.05) {
			//std::cout << "Passei a primeira condi��o!\n";
			black = 0;
			white = 0;
			for (int w = 0; w < patchWidth; w++) {
				for (int h = 0; h < patchHeight; h++) {
					pixel = patch.at<char>(h, w);
					if (pixel == 255)
						white++;
					else black++;
				}
			}
			if (black > white)
			{
				//std::cout << "encontrei\n";
				imshow("aq", patch);
				markers.push_back(candidates[i]);
			}


		}
	
	
	}

	return markers;

}




cv::Mat compute_marker(cv::Mat img, cv::Mat original) 
{
	cv::Mat threshImage, warped;
	std::vector<std::vector<cv::Point> > contours;
	std::vector< std::vector< Point2f > > markers;
	double cnt_len;
	std::vector< std::vector< Point2f > > candidates, biggerCandidates;
	std::vector< std::vector< Point > > contoursOut, biggerContours;
	//cv::aruco::DetectorParameters* params = cv::aruco::DetectorParameters::create();
	adaptiveThreshold(img, threshImage, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 5, 3);

	findContours(threshImage, contours, RETR_LIST, CHAIN_APPROX_NONE);
	Mat drawing = Mat::zeros(img.size(), CV_8UC3);



	for (unsigned int i = 0; i < contours.size(); i++) {
		std::vector< Point > approxCurve;
		bool issquare;
		cnt_len = arcLength(contours[i], true);


			approxPolyDP(contours[i], approxCurve, double(contours[i].size()) * 0.03, true);
			//std::cout << "SIZE2:" << cnt_len << "\n";
			//std::cout << contourArea(contours[i]) << "\n";
			//std::cout << "COL:" << img.cols << "ROWS" << img.rows << "\n";
			if (contourArea(approxCurve) > 80 && contourArea(approxCurve) < 0.2 * img.cols * img.rows) {
				//approxPolyDP(contours[i], approxCurve, double(cnt_len * params->polygonalApproxAccuracyRate), true);
				//std::cout << "SIZE2:" << params->polygonalApproxAccuracyRate << "\n";
				
				if (approxCurve.size() == 4 && isContourConvex(approxCurve)) {
					issquare = compare_distance(approxCurve);
					if (!(issquare)) continue;

					std::vector< Point2f > currentCandidate;
					currentCandidate.resize(4);
					for (int j = 0; j < 4; j++) {
						currentCandidate[j] = Point2f((float)approxCurve[j].x, (float)approxCurve[j].y);
					}
					candidates.push_back(currentCandidate);
					contoursOut.push_back(contours[i]);
				}
				//std::cout << approxCurve << "ENCONTREI \n";

			}
		}
		//}
	for (unsigned int i = 0; i < candidates.size(); i++) {
		double dx1 = candidates[i][1].x - candidates[i][0].x;
		double dy1 = candidates[i][1].y - candidates[i][0].y;
		double dx2 = candidates[i][2].x - candidates[i][0].x;
		double dy2 = candidates[i][2].y - candidates[i][0].y;
		double crossProduct = (dx1 * dy2) - (dy1 * dx2);

		if (crossProduct < 0.0) { // not clockwise direction
			swap(candidates[i][1], candidates[i][3]);
		}
	}

	
	std::cout << "Before grouping: " << candidates.size() << "\n";
	/*
	std::vector<int> candGroup;
	candGroup.resize(candidates.size(), -1);
	std::vector< std::vector<unsigned int> > groupedCandidates;
	//std::cout << "candGroup: " << candGroup[0] << "\n";

	for (unsigned int i = 0; i < candidates.size(); i++) {
		for (unsigned int j = i + 1; j < candidates.size(); j++) {

			int minimumPerimeter = min((int)contours[i].size(), (int)contours[j].size());

			// fc is the first corner considered on one of the markers, 4 combinations are possible
			for (int fc = 0; fc < 4; fc++) {
				double distSq = 0;
				for (int c = 0; c < 4; c++) {
					// modC is the corner considering first corner is fc
					int modC = (c + fc) % 4;
					distSq += (candidates[i][modC].x - candidates[j][c].x) *
						(candidates[i][modC].x - candidates[j][c].x) +
						(candidates[i][modC].y - candidates[j][c].y) *
						(candidates[i][modC].y - candidates[j][c].y);
				}
				distSq /= 4.;

				// if mean square distance is too low, remove the smaller one of the two markers
				double minMarkerDistancePixels = double(minimumPerimeter) * 0.05;
				if (distSq < minMarkerDistancePixels * minMarkerDistancePixels) {

					// i and j are not related to a group
					if (candGroup[i] < 0 && candGroup[j] < 0) {
						// mark candidates with their corresponding group number
						candGroup[i] = candGroup[j] = (int)groupedCandidates.size();

						// create group
						std::vector<unsigned int> grouped;
						grouped.push_back(i);
						grouped.push_back(j);
						groupedCandidates.push_back(grouped);
					}
					// i is related to a group
					else if (candGroup[i] > -1 && candGroup[j] == -1) {
						int group = candGroup[i];
						candGroup[j] = group;

						// add to group
						groupedCandidates[group].push_back(j);
					}
					// j is related to a group
					else if (candGroup[j] > -1 && candGroup[i] == -1) {
						int group = candGroup[j];
						candGroup[i] = group;

						// add to group
						groupedCandidates[group].push_back(i);
					}
				}
			}
		}
	}
	
	std::cout << "After grouping: " << groupedCandidates.size() << "\n";

	

	for (unsigned int i = 0; i < groupedCandidates.size(); i++) {
		int smallerIdx = groupedCandidates[i][0];
		int biggerIdx = -1;

		// evaluate group elements
		for (unsigned int j = 1; j < groupedCandidates[i].size(); j++) {
			size_t currPerim = contours[groupedCandidates[i][j]].size();

			// check if current contour is bigger
			if (biggerIdx < 0)
				biggerIdx = groupedCandidates[i][j];
			else if (currPerim >= contours[biggerIdx].size())
				biggerIdx = groupedCandidates[i][j];

			// check if current contour is smaller
			if (currPerim < contours[smallerIdx].size())
				smallerIdx = groupedCandidates[i][j];
		}
		// add contours und candidates
		if (biggerIdx > -1) {

			biggerCandidates.push_back(candidates[biggerIdx]);
			biggerContours.push_back(contoursOut[biggerIdx]);

			
		}
	}

	std::cout << "After joining: " << biggerCandidates.size() << "\n";
	*/
	std::vector <cv::Mat> warpedCandidates ;

	//biggerCandidates = candidates;


	for (unsigned int i = 0; i < candidates.size(); i++) {
		drawContours(drawing, contoursOut, (int)i, (255, 255, 255), 2, LINE_8);
		warped = four_point_transform(img, candidates[i]);
		threshold(warped, warped, 125, 255, THRESH_BINARY | THRESH_OTSU);
		warpedCandidates.push_back(warped);
		//cv::imshow("warped", warped);
		//waitKey(0);
		}
	markers = match_warped(candidates, img, warpedCandidates);
	cv::Rect rect_aux;
	//std::cout <<  "ENCONTREI \n";
	for (unsigned int i = 0; i < markers.size(); i++)
	{
		rect_aux = boundingRect(markers[i]);
		rectangle(original, rect_aux, 255, 5);
	}

	

	cv::imshow("Drawing", drawing);


	//waitKey(0);




		
	

	return original;

}









void main()
{
	//VideoCapture cap(0);
	VideoCapture cap("D:/Desktop/Python/UAV_markers_test/New_Images/C_fast_short.MOV");
	cv::Mat img, img_original;
	cv::Size sz = img.size();
	int imageWidth = sz.width;
	int imageHeight = sz.height;
	int dim, width, height, scale_percent = 150;
	width = int(imageWidth * scale_percent / 100);
	height = int(imageHeight * scale_percent / 100);
	bool bSuccess;

	while (cap.read(img))
	{
		
		
		
		cv::resize(img, img, cv::Size(img.cols * 1.5, img.rows * 1.5), 0, 0, CV_INTER_LINEAR);

		img_original = img;

		cvtColor(img, img, CV_BGR2GRAY);
		
		img = compute_marker(img, img_original);

		cv::imshow("Window", img);

		if (waitKey(1) == 27)
		{
			std::cout << "Esc key is pressed by user. Stopping the video\n";
			break;
		}

	}

}
