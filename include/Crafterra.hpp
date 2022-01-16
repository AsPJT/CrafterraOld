﻿/*##########################################################################################

	Crafterra Library 🌏

	[Planning and Production]
	2017-2022 Kasugaccho
	2018-2022 As Project

	[Contact Us]
	wanotaitei@gmail.com
	https://github.com/AsPJT/Crafterra

	[License]
	Distributed under the CC0 1.0.
	https://creativecommons.org/publicdomain/zero/1.0/

##########################################################################################*/

#ifndef INCLUDED_CRAFTERRA_LIBRARY_CRAFTERRA_HPP
#define INCLUDED_CRAFTERRA_LIBRARY_CRAFTERRA_HPP

//##########################################################################################
// Macro
// マクロ定義 ( 完成 & 更新あり )
#include <Crafterra/Macro/Library.hpp>
#include <Crafterra/Macro/Version.hpp>
#include <Crafterra/Macro/ThirdParty.hpp>
#include <Crafterra/Macro/New.hpp>
//##########################################################################################
// Data Type
// プリミティブ型定義 ( 完成 )
#include <Crafterra/DataType/PrimitiveDataType.hpp>
// Crafterra 固有のプリミティブ型定義 ( 骨組みは完成 )
#include <Crafterra/DataType/CrafterraPrimitiveDataType.hpp>
// テンプレート型 ( ほぼ完成 )
#include <Crafterra/DataType/StringDataType.hpp>
#include <Crafterra/DataType/ArrayDataType.hpp>
#include <Crafterra/DataType/VectorDataType.hpp>
//##########################################################################################

#include <Crafterra/Enum/CrafterraEnum.hpp>

#include <Crafterra/Basic/Size2D.hpp>

namespace Crafterra {

	class Font;
	class Music;
	class MapChipImage;
	class CharacterChipImage;

	class Resource {

		// 各種素材のポインタ
	private:
		Font* font = nullptr;
		Music* music = nullptr;
		MapChipImage* map_chip = nullptr;
		CharacterChipImage* character_chip = nullptr;

	public:
		void setFont(Font& font_) { this->font = &font_; }
		Font& getFont() { return *(this->font); }
		void setMusic(Music& music_) { this->music = &music_; }
		Music& getMusic() { return *(this->music); }
		void setMapChip(MapChipImage& map_chip_) { this->map_chip = &map_chip_; }
		MapChipImage& getMapChip() { return *(this->map_chip); }
		void setCharacterChip(CharacterChipImage& character_chip_) { this->character_chip = &character_chip_; }
		CharacterChipImage& getCharacterChip() { return *(this->character_chip); }

	private:
		int window_width = 0;
		int window_height = 0;

	public:
		void setWindowWidth(const int window_width_) { this->window_width = window_width_; }
		void setWindowHeight(const int window_height_) { this->window_height = window_height_; }
		int getWindowWidth() const { return this->window_width; }
		int getWindowHeight() const { return this->window_height; }

	};



}


// Crafterra のメイン関数を宣言
#ifndef CRAFTERRA_MAIN_FUNCTION
#define CRAFTERRA_MAIN_FUNCTION
namespace Crafterra {
	namespace System {
		void crafterraMain(::Crafterra::Resource&);
	}
}
#endif // CRAFTERRA_MAIN_FUNCTION

#include <Crafterra/DataType/PrimitiveDataType.hpp>

namespace Crafterra {
	namespace System {
		// 初期のウィンドウの幅
		constexpr int init_window_width = 1280;
		// 初期のウィンドウの高さ
		constexpr int init_window_height = 720;
	}

	// マップサイズ
	constexpr ::Crafterra::DataType::IndexUint size_x = 512;
	constexpr ::Crafterra::DataType::IndexUint size_y = 512;

}



// 初回読み込み
#include <Crafterra/Basic/InitRead.hpp>


namespace Crafterra {
	namespace Color {
		// 色クラス ( 暫定 )
		using Color3 = unsigned int;
	}
}

#include <Crafterra/Basic/CoordinateSystem.hpp>

#include <Crafterra/Map/MapChip.hpp>

//##########################################################################################
#ifdef CRAFTERRA_USE_DXLIB
// 入力系
#include <Crafterra/ThirdParty/DxLib/DxKeyboard.hpp>
#include <Crafterra/ThirdParty/DxLib/DxFont.hpp>
#include <Crafterra/ThirdParty/DxLib/DxMusic.hpp>
#include <Crafterra/ThirdParty/DxLib/DxMapChip.hpp>
#include <Crafterra/ThirdParty/DxLib/DxCharacterChip.hpp>

// DxLib 系の中でも 1 番遅く include する
#include <Crafterra/ThirdParty/DxLib/CrafterraForDxLib.hpp>

#else

namespace Crafterra {
	class Font {};
	class Music {};
	class MapChipImage {};
	class CharacterChipImage {};

}

#endif // CRAFTERRA_USE_DXLIB
//##########################################################################################

#include <Crafterra/Generation/FieldMap.hpp>

#endif //Included Crafterra Library