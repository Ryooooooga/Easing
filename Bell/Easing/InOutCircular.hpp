//=====================================================================
// Copyright (c) 2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#pragma once

#include "OutCircular.hpp"

namespace Bell::Easing {

	/**
	 * @brief      ease in out circ
	 */
	template <typename FloatType>
	class InOutCircular
	{
		static_assert(std::is_floating_point<FloatType>::value, "");

	public:
		using value_type = FloatType;

		FloatType operator()(FloatType t) const noexcept
		{
			return
				t < FloatType(0.0) ? FloatType(0) :
				t > FloatType(1.0) ? FloatType(1) :
				t < FloatType(0.5) ? InCircular<FloatType>()(t*2)/2 :
				(OutCircular<FloatType>()(t*2 - FloatType(1)) + FloatType(1))/2;
		}
	};

}	//	namespace Bell::Easing
