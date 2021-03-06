/*
 * Copyright 2012 Kitware, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of this project nor the names of its contributors
 *       may be used to endorse or promote products derived from this software
 *       without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef file_io_h_
#define file_io_h_

#include "depth_config.h"

#include <vcl_string.h>
#include <vcl_vector.h>
#include <vcl_utility.h>
#include <vil/vil_image_view.h>
#include <vpgl/vpgl_perspective_camera.h>
#include <vgl/vgl_point_3d.h>
#include <vgl/vgl_point_2d.h>
#include <vul/vul_sequence_filename_map.h>


namespace super3d
{

/// Load a camera file with sequence of cameras in ASCII format: i K R t
/// where i is the frame number, K is the calibration matrix,
/// R is the rotation matrix, and t is the translation vector
/// \returns A vector of perspective cameras
SUPER3D_DEPTH_EXPORT
vcl_vector<vpgl_perspective_camera<double> >
load_cams(const vcl_string& filename, vul_sequence_filename_map frame_seq);

SUPER3D_DEPTH_EXPORT
vpgl_perspective_camera<double>
load_cam(const vcl_string& filename);

/// Find all frames matching the format string and extract the frame number.
/// \returns A vector of image views
SUPER3D_DEPTH_EXPORT
vcl_vector<vil_image_view<double> >
load_frames(vul_sequence_filename_map frame_seq, vcl_vector<vcl_string> &filenames, bool color = false);

/// Load an exposure file with parameters for linear exposure compensation
/// Uses a file sequence
/// \returns A vector of (scale, offest) pair
SUPER3D_DEPTH_EXPORT
vcl_vector<vcl_pair<double,double> >
load_exposure(const std::string& filename, vul_sequence_filename_map frame_seq);

/// Load an exposure file with parameters for linear exposure compensation
/// Uses a list of frames
/// \returns A vector of (scale, offest) pair
SUPER3D_DEPTH_EXPORT
vcl_vector<vcl_pair<double,double> >
load_exposure(const std::string& filename, const vcl_vector<int> &framelist);

//Load camera from a file per camera
SUPER3D_DEPTH_EXPORT
vpgl_perspective_camera<double>
load_cam(const vcl_string& filename);

//Load cameras from a file per camera
//Assume cameras are in directory named %04d.krtd
SUPER3D_DEPTH_EXPORT
void
load_krtd_cams(const vcl_string& directory,
               vcl_vector<int> &framelist,
               vcl_vector<vpgl_perspective_camera<double> > &cameras);

//Load cameras from a single camera file with a framelist
SUPER3D_DEPTH_EXPORT
void load_cams(const char *camerafile,
               vcl_vector<int> &framelist,
               vcl_vector<vpgl_perspective_camera<double> > &cameras);

/// Loads images from a file list of frames paths
/// \param framefile file that lists frame number and frame paths
/// \param directory the working direction from which the framefile appends its paths to
/// \param filenames vector of frame files that were read
/// \param framelist vector of indices of the read frames
/// \param frames images that were read and converted to greyscale
SUPER3D_DEPTH_EXPORT
void load_from_frame_file(const char *framefile,
                          const vcl_string &directory,
                          vcl_vector<vcl_string> &filenames,
                          vcl_vector<int> &framelist,
                          vcl_vector<vil_image_view<double> > &frames,
                          bool color = false,
                          bool rgb12 = false);

/// read a flow file into 2-band image
SUPER3D_DEPTH_EXPORT
bool read_flow_file(vil_image_view<double> &flowimg, const char* filename);

}  // end namespace super3d

#endif // file_io_h_
