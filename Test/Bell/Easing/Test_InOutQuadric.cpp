//=====================================================================
// Copyright (c) 2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#include "../../../Bell/Easing/InOutQuadratic.hpp"

namespace Bell::Easing {

	static_assert(InOutQuadratic<double>()(-1./4) ==  0./16, "");
	static_assert(InOutQuadratic<double>()( 0./4) ==  0./16, "");
	static_assert(InOutQuadratic<double>()( 1./4) ==  2./16, "");
	static_assert(InOutQuadratic<double>()( 2./4) ==  8./16, "");
	static_assert(InOutQuadratic<double>()( 3./4) == 14./16, "");
	static_assert(InOutQuadratic<double>()( 4./4) == 16./16, "");
	static_assert(InOutQuadratic<double>()( 5./4) == 16./16, "");

}	//	namespace Bell::Easing
