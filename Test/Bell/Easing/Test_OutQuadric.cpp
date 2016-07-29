//=====================================================================
// Copyright (c) 2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#include "../../../Bell/Easing/OutQuadratic.hpp"

namespace Bell::Easing {

	static_assert(OutQuadratic<double>()(-1./4) ==  0./16, "");
	static_assert(OutQuadratic<double>()( 0./4) ==  0./16, "");
	static_assert(OutQuadratic<double>()( 1./4) ==  7./16, "");
	static_assert(OutQuadratic<double>()( 2./4) == 12./16, "");
	static_assert(OutQuadratic<double>()( 3./4) == 15./16, "");
	static_assert(OutQuadratic<double>()( 4./4) == 16./16, "");
	static_assert(OutQuadratic<double>()( 5./4) == 16./16, "");

}	//	namespace Bell::Easing
