//=====================================================================
// Copyright (c) 2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#pragma once

#include "InCircular.hpp"

namespace Bell::Easing {

	/**
	 * @brief      ease out circ
	 */
	template <typename FloatType>
	class OutCircular
	{
		static_assert(std::is_floating_point<FloatType>::value, "");

	public:
		using value_type = FloatType;

		constexpr FloatType operator()(FloatType t) const noexcept
		{
			return FloatType(1) - InCircular<FloatType>()(FloatType(1) - t);
		}
	};

}	//	namespace Bell::Easing
