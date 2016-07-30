//=====================================================================
// Copyright (c) 2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#include <functional>
#include <DxLib.h>
#include "Bell/Easing.hpp"

using namespace Bell::Easing;
using namespace Bell::Math;

constexpr float W = 200;
constexpr float H = 320;

struct Block
{
	std::function<float(float)> f;
	const TCHAR* name;
	float x, y;
};

const Block blocks[] = {
	{ Linear			<float>()		, _T("Linear"			), 0*W, 0*H },
	{ Step				<float>(0.5f)	, _T("Step(0.5)"		), 0*W, 1*H },
	{ Step				<float>(1.0f)	, _T("Step(1.0)"		), 0*W, 2*H },

	{ InQuadratic		<float>()		, _T("InQuadratic"		), 1*W, 0*H },
	{ OutQuadratic		<float>()		, _T("OutQuadratic"		), 1*W, 1*H },
	{ InOutQuadratic	<float>()		, _T("InOutQuadratic"	), 1*W, 2*H },

	{ InExponential		<float>()		, _T("InExponential"	), 2*W, 0*H },
	{ OutExponential	<float>()		, _T("OutExponential"	), 2*W, 1*H },
	{ InOutExponential	<float>()		, _T("InOutExponential"	), 2*W, 2*H },

	{ InBack			<float>()		, _T("InBack"			), 3*W, 0*H },
	{ OutBack			<float>()		, _T("OutBack"			), 3*W, 1*H },
	{ InOutBack			<float>()		, _T("InOutBack"		), 3*W, 2*H },

	{ InElastic			<float>()		, _T("InElastic"		), 4*W, 0*H },
	{ OutElastic		<float>()		, _T("OutElastic"		), 4*W, 1*H },
	{ InOutElastic		<float>()		, _T("InOutElastic"		), 4*W, 2*H },

	{ InBounce			<float>()		, _T("InBounce"			), 5*W, 0*H },
	{ OutBounce			<float>()		, _T("OutBounce"		), 5*W, 1*H },
	{ InOutBounce		<float>()		, _T("InOutBounce"		), 5*W, 2*H },
};

int main()
{
	DxLib::ChangeWindowMode(true);
	DxLib::SetGraphMode(1200, 960, 32);
	DxLib::SetMainWindowText(_T("Easing Demo"));
	DxLib::SetOutApplicationLogValidFlag(false);

	if (DxLib::DxLib_Init() == -1) return -1;
	DxLib::SetDrawScreen(DX_SCREEN_BACK);

	int counter	= 0;
	int accent	= DxLib::GetColor( 22, 149, 163);
	int accent2	= DxLib::GetColor(235, 127,   0);
	int main	= DxLib::GetColor(172, 240, 242);
	int base	= DxLib::GetColor( 34,  83, 120);
	int font	= DxLib::CreateFontToHandle(_T("Meiryo UI"), 22, 2);

	while (DxLib::ProcessMessage() == 0)
	{
		DxLib::ClearDrawScreen();
		DxLib::clsDx();

		DxLib::DrawBox(0, 0, 1280, 960, base, true);

		for (auto&& block : blocks)
		{
			float t = (std::min)((counter % 120) / 60.f, 1.f);

			{
				DrawBoxAA(
					block.x + 0, block.y + 0,
					block.x + W, block.y + H,
					main, false);
			}

			{
				float x = block.x + W/2;
				float y = block.y + H/4 + 20;
				float r = (block.f(t) + (counter / 120)) * pi<float>/2;
				float c = std::cos(r);
				float s = std::sin(r);

				float vx[4] = { -50.f, -50.f, +50.f, +50.f };
				float vy[4] = { -50.f, +50.f, -50.f, +50.f };

				for (int i = 0; i < 4; i++)
				{
					float u = vx[i];
					float v = vy[i];

					vx[i] = u * c - v * s;
					vy[i] = u * s + v * c;
				}

				DxLib::DrawTriangleAA(
					x + vx[0], y + vy[0],
					x + vx[1], y + vy[1],
					x + vx[2], y + vy[2],
					accent, true);
				DxLib::DrawTriangleAA(
					x + vx[1], y + vy[1],
					x + vx[2], y + vy[2],
					x + vx[3], y + vy[3],
					accent, true);
				DxLib::DrawTriangleAA(
					x + vx[0], y + vy[0],
					x + vx[1], y + vy[1],
					x + vx[2], y + vy[2],
					main, false);
				DxLib::DrawTriangleAA(
					x + vx[1], y + vy[1],
					x + vx[2], y + vy[2],
					x + vx[3], y + vy[3],
					main, false);
			}

			{
				float x = block.x + W/2   - 50.f;
				float y = block.y + H/4*3 + 50.f;

				DxLib::DrawBoxAA(
					x +   0.f, y - 100.f,
					x + 100.f, y +   0.f,
					main, false);

				DxLib::LINEDATA lines[100];

				for (int i = 0; i < 100; i++)
				{
					lines[i].x1 = static_cast<int>(x + i + 0), lines[i].y1 = static_cast<int>(y - block.f((i+0)/100.f) * 100.f);
					lines[i].x2 = static_cast<int>(x + i + 1), lines[i].y2 = static_cast<int>(y - block.f((i+1)/100.f) * 100.f);
					lines[i].color	= main;
				}

				DrawLineSet(lines, 100);
				
				DrawLineAA(
					x + t*100.f, y - block.f(t) * 100.f,
					x + t*100.f, y -                0.f,
					accent2);
			}

			{
				DxLib::DrawStringFToHandle(block.x + 3, block.y + 3, block.name, main, font);
			}
		}

		counter++;

		DxLib::ScreenFlip();
	}

	DxLib::DxLib_End();

	return 0;
}
