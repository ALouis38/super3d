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

#ifndef ROF_NORMALS_H_
#define ROF_NORMALS_H_

#include "depth_config.h"
#include "world_space.h"

#include <vil/vil_image_view.h>


namespace super3d
{

SUPER3D_DEPTH_EXPORT
void
compute_normals_eig(const vil_image_view<double> &d,
                    vil_image_view<double> &bp,
                    vil_image_view<double> &n,
                    world_space *ws,
                    int neighborhood,
                    double thresh,
                    bool normalize = true);


SUPER3D_DEPTH_EXPORT
void
normals_rof(vil_image_view<double> &n,
            const vil_image_view<double> &d,
            vil_image_view<double> &bp,
            world_space *ws,
            const vil_image_view<double> &g,
            unsigned int iterations,
            int neighborhood,
            double lambda,
            double step,
            double epsilon);


SUPER3D_DEPTH_EXPORT
void huber_normals_rof_preproc(const vil_image_view<double> &bp,
                               const vil_image_view<double> &d,
                               vcl_vector<vcl_vector<vnl_matrix_fixed<double, 2, 2> > > &AtAinv,
                               vcl_vector<vcl_vector<vnl_vector_fixed<double, 2> > > &Atb,
                               double lambda,
                               double step,
                               int neighborhood,
                               double depth_thresh);


SUPER3D_DEPTH_EXPORT
void
huber_normals_rof_update(vil_image_view<double> &q,
                         vil_image_view<double> &n,
                         vcl_vector<vcl_vector<vnl_matrix_fixed<double, 2, 2> > > &AtAinv,
                         vcl_vector<vcl_vector<vnl_vector_fixed<double, 2> > > &Atb,
                         const vil_image_view<double> &g,
                         double lambda,
                         double step,
                         double epsilon);


SUPER3D_DEPTH_EXPORT
void
huber_normals_rof_update(vil_image_view<double> &q,
                         vil_image_view<double> &n,
                         const vil_image_view<double> &bp,
                         const vil_image_view<double> &d,
                         const vil_image_view<double> &g,
                         int neighborhood,
                         double lambda,
                         double step,
                         double epsilon,
                         double thresh);

} // end namespace super3d

#endif
