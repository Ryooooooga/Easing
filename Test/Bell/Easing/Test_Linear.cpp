//=====================================================================
// Copyright (c) 2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#include "../../../Bell/Easing/Linear.hpp"

namespace Bell::Easing {

	static_assert(Linear<double>()(-1./4) == 0./4, "");
	static_assert(Linear<double>()( 0./4) == 0./4, "");
	static_assert(Linear<double>()( 1./4) == 1./4, "");
	static_assert(Linear<double>()( 2./4) == 2./4, "");
	static_assert(Linear<double>()( 3./4) == 3./4, "");
	static_assert(Linear<double>()( 4./4) == 4./4, "");
	static_assert(Linear<double>()( 5./4) == 4./4, "");

}	//	namespace Bell::Easing
