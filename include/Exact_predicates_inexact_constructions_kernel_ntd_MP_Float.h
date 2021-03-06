// Copyright (c) 2003  
// Utrecht University (The Netherlands),
// ETH Zurich (Switzerland),
// INRIA Sophia-Antipolis (France),
// Max-Planck-Institute Saarbruecken (Germany),
// and Tel-Aviv University (Israel).  All rights reserved. 
//
// This file is part of CGAL (www.cgal.org); you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; either version 3 of the License,
// or (at your option) any later version.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL$
// $Id$
// 
//
// Author(s)     : Menelaos Karavelas, Sylvain Pion

#ifndef CGAL_EXACT_PREDICATES_INEXACT_CONSTRUCTIONS_KERNEL_MP_FLOAT_H
#define CGAL_EXACT_PREDICATES_INEXACT_CONSTRUCTIONS_KERNEL_MP_FLOAT_H

#include <CGAL/Simple_cartesian.h>
#include <CGAL/Filtered_kernel.h>
#include <CGAL/Triangulation_structural_filtering_traits.h>

// Precision NTD
// V1_08_08_2016
#include <CGAL/MP_Float.h> 
#include <CGAL/Lazy_exact_nt.h> 
#include <CGAL/Gmpq.h>

//typedef CGAL::Lazy_exact_nt<CGAL::Quotient<CGAL::MP_Float> > NT_MP;

//typedef CGAL::Quotient<CGAL::MP_Float> NT_MP;

typedef CGAL::Lazy_exact_nt<CGAL::Gmpq> NT_MP;
//typedef CGAL::Gmpq NT_MP;

//typedef double NT_MP;

namespace CGAL {

// The following is equivalent to Filtered_kernel< Simple_cartesian<double> >,
// but it's shorter in terms of template name length (for error messages, mangling...).

class Epick_MP_Float
  : public Filtered_kernel_adaptor<
               Type_equality_wrapper< Simple_cartesian<NT_MP>::Base<Epick_MP_Float>::Type, Epick_MP_Float >,
#ifdef CGAL_NO_STATIC_FILTERS
               false >
#else
               true >
#endif
{};

// Type_equality_wrapper< Simple_cartesian<double>::Base<Epick_MP_Float>::Type, Epick_MP_Float >,

typedef Epick_MP_Float Exact_predicates_inexact_constructions_kernel_MP_Float;

template <>
struct Triangulation_structural_filtering_traits<Epick_MP_Float> {
  typedef Tag_true Use_structural_filtering_tag;
};

} // namespace CGAL

#endif // CGAL_EXACT_PREDICATES_INEXACT_CONSTRUCTIONS_KERNEL_MP_FLOAT_H
