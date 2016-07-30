//=====================================================================
// Copyright (c) 2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#include "../../../Bell/Easing/OutQuartic.hpp"

namespace Bell::Easing {

	static_assert(OutQuartic<double>()(-1./4) ==   0./256, "");
	static_assert(OutQuartic<double>()( 0./4) ==   0./256, "");
	static_assert(OutQuartic<double>()( 1./4) == 175./256, "");
	static_assert(OutQuartic<double>()( 2./4) == 240./256, "");
	static_assert(OutQuartic<double>()( 3./4) == 255./256, "");
	static_assert(OutQuartic<double>()( 4./4) == 256./256, "");
	static_assert(OutQuartic<double>()( 5./4) == 256./256, "");

}	//	namespace Bell::Easing
