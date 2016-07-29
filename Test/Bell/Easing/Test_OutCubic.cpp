//=====================================================================
// Copyright (c) 2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#include "../../../Bell/Easing/OutCubic.hpp"

namespace Bell::Easing {

	static_assert(OutCubic<double>()(-1./4) ==  0./64, "");
	static_assert(OutCubic<double>()( 0./4) ==  0./64, "");
	static_assert(OutCubic<double>()( 1./4) == 37./64, "");
	static_assert(OutCubic<double>()( 2./4) == 56./64, "");
	static_assert(OutCubic<double>()( 3./4) == 63./64, "");
	static_assert(OutCubic<double>()( 4./4) == 64./64, "");
	static_assert(OutCubic<double>()( 5./4) == 64./64, "");

}	//	namespace Bell::Easing
