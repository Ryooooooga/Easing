//=====================================================================
// Copyright (c) 2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#pragma once

#include "InElastic.hpp"

namespace Bell::Easing {

	/**
	 * @brief      ease in out elastic
	 */
	template <typename FloatType>
	class InOutElastic
	{
		static_assert(std::is_floating_point<FloatType>::value, "");

		InElastic<FloatType> in_;

	public:
		using value_type = FloatType;

		InOutElastic(FloatType a = FloatType(1.0), FloatType p = FloatType(0.3)) noexcept
			: in_(a, p) {}

		FloatType operator()(FloatType t) const noexcept
		{
			return
				t < FloatType(0.0) ? FloatType(0) :
				t > FloatType(1.0) ? FloatType(1) :
				t < FloatType(0.5) ? in_(t*2)/2 :
				(FloatType(2) - in_((1-t)*2))/2;
		}
	};

}	//	namespace Bell::Easing
