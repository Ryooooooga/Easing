//=====================================================================
// Copyright (c) 2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#pragma once

#include "OutQuartic.hpp"

namespace Bell::Easing {

	/**
	 * @brief      ease in out quart
	 */
	template <typename FloatType>
	class InOutQuartic
	{
		static_assert(std::is_floating_point<FloatType>::value, "");

	public:
		using value_type = FloatType;

		constexpr FloatType operator()(FloatType t) const noexcept
		{
			return
				t < FloatType(0.0) ? FloatType(0) :
				t > FloatType(1.0) ? FloatType(1) :
				t < FloatType(0.5) ? InQuartic<FloatType>()(t*2)/2 :
				(OutQuartic<FloatType>()(t*2 - FloatType(1)) + FloatType(1))/2;
		}
	};

}	//	namespace Bell::Easing
