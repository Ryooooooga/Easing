//=====================================================================
// Copyright (c) 2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#include "../../../Bell/Easing/InQuadratic.hpp"

namespace Bell::Easing {

	static_assert(InQuadratic<double>()(-1./4) ==  0./16, "");
	static_assert(InQuadratic<double>()( 0./4) ==  0./16, "");
	static_assert(InQuadratic<double>()( 1./4) ==  1./16, "");
	static_assert(InQuadratic<double>()( 2./4) ==  4./16, "");
	static_assert(InQuadratic<double>()( 3./4) ==  9./16, "");
	static_assert(InQuadratic<double>()( 4./4) == 16./16, "");
	static_assert(InQuadratic<double>()( 5./4) == 16./16, "");

}	//	namespace Bell::Easing
