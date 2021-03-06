# Indexed mesh library algorithms
#
# Originally from vxl/contrib/brl/bbas/imesh/algo

set(imesh_algo_headers
    imesh_algo_config.h
    imesh_transform.h
    imesh_intersect.h
    imesh_operations.h
    imesh_pca.h
    imesh_project.h
    imesh_detect.h
    imesh_kd_tree.h      imesh_kd_tree.txx
    imesh_render.h
    imesh_imls_surface.h imesh_imls_surface.txx
   )

set(imesh_algo_sources
    imesh_transform.cxx
    imesh_intersect.cxx
    imesh_operations.cxx
    imesh_pca.cxx
    imesh_project.cxx
    imesh_detect.cxx
    imesh_kd_tree.cxx
    imesh_render.cxx
    imesh_imls_surface.cxx
   )
aux_source_directory(Templates imesh_algo_sources)

if(VXL_NETLIB_FOUND)
  include_directories(${VXL_NETLIB_INCLUDE_DIR})
  set(imesh_algo_headers ${imesh_algo_headers} imesh_generate_mesh.h)
  set(imesh_algo_sources ${imesh_algo_sources} imesh_generate_mesh.cxx)
endif(VXL_NETLIB_FOUND)

super3d_install_headers(${imesh_algo_headers} SUBDIR imesh/algo)
super3d_add_library(imesh_algo ${imesh_algo_headers} ${imesh_algo_sources})

if(VXL_NETLIB_FOUND)
  #target_link_libraries( imesh_algo imesh vpgl bpgl bpgl_algo vgl_algo vgl vnl_algo vnl vil netlib)
  target_link_libraries( imesh_algo imesh vpgl vgl_algo vgl vnl_algo vnl vil netlib )
else(VXL_NETLIB_FOUND)
  target_link_libraries( imesh_algo imesh vpgl vgl_algo vgl vnl_algo vnl vil )
endif(VXL_NETLIB_FOUND)
