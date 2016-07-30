//=====================================================================
// Copyright (c) 2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#include "../../../Bell/Easing/Step.hpp"

namespace Bell::Easing {

	static_assert(Step<double>(0.5)(-1./4) == 0., "");
	static_assert(Step<double>(0.5)( 0./4) == 0., "");
	static_assert(Step<double>(0.5)( 1./4) == 0., "");
	static_assert(Step<double>(0.5)( 2./4) == 1., "");
	static_assert(Step<double>(0.5)( 3./4) == 1., "");
	static_assert(Step<double>(0.5)( 4./4) == 1., "");
	static_assert(Step<double>(0.5)( 5./4) == 1., "");

}	//	namespace Bell::Easing
