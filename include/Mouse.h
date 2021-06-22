/*
* Mouse position prediction.
* See COPYRIGHT file at the top of the source tree.
*
* This product includes software developed by the
* STARGUE Project (http://www.stargue.org/).
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the STARGUE License Statement and
* the GNU General Public License along with this program. If not,
* see <http://www.lsstcorp.org/LegalNotices/>.
*/

/**
 * @file Mouse.h
 *
 * @brief Mouse prediction main functions. 
 *
 * @author Adama Zouma
 * 
 * @Contact: stargue49@gmail.com
 *
 */
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/video/tracking.hpp"
#include "ConstantsMouse.h"

#include<iostream>

namespace za {
/* ============================================================================
 * Function Declaration
 * ============================================================================
 */

/**
 * \brief Predict mouse position.
 *
 * \details Rely on current mouse position to determine its next position.
 *
 * \param positions [in] mouse position, type is vector of opencv Point
 *
 * \return Next position, type is opencv Point
 * 
 * 
 */
cv::Point predictNextPosition(std::vector<cv::Point> &positions);

/**
 * \brief Move mouse callback.
 *
 * \details Callback function to process mouse movement. 
 *
 * \param event [in] mouse event, type is int
 * \param x [in] mouse x position, type is int
 * \param y [in] mouse y position, type is int
 * \param flags [in] flag, type is int
 * \param userData [in] argument of the function, type is void
 *
 * \return type is void
 * 
 * 
 */
void mouseMoveCallback(int event, int x, int y, int flags, void* userData);

/**
 * \brief Show a detected plate on an image.
 *
 * \details The input image is processed, then if a plate is detected a rectangle is drawn around it. 
 *
 * \param img [in] argument of the function, type is opencv Mat
 * \param center [in] argument of the function, type is opencv Point
 * \param color [in] argument of the function, type is opencv Scalar
 *
 * \return type is void
 * 
 * 
 */
void drawCross(cv::Mat &img, cv::Point center, cv::Scalar color);

}