/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the declaration of Settings that contains constants
    to set up the game and methods to load multimedia files.
*/

#pragma once

#include <filesystem>
#include <string>
#include <unordered_map>

namespace fs = std::filesystem;

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

struct Settings
{
    static const fs::path GRAPHICS_PATH;
    static const fs::path SOUNDS_PATH;
    static const fs::path FONTS_PATH;

    static constexpr int WINDOW_WIDTH{1020};
    static constexpr int WINDOW_HEIGHT{540};
    static constexpr int VIRTUAL_WIDTH{512};
    static constexpr int VIRTUAL_HEIGHT{255};
    static constexpr float BIRD_WIDTH{39.f};
    static constexpr float BIRD_HEIGHT{28.f};
    static constexpr float BIRD_SPEED{600.f};
    static constexpr float LOG_WIDTH{70.f};
    static constexpr float LOG_HEIGHT{255.f};
    static constexpr float LOGS_GAP{90.f};
    static constexpr float LOGS_SPEED{25.f};
    static constexpr float GROUND_HEIGHT{16.f};
    static constexpr float BACKGROUND_LOOPING_POINT{1024.f};
    static constexpr float MAIN_SCROLL_SPEED{100.f};
    static constexpr float BACK_SCROLL_SPEED{50.f}; // MAIN_SCROLL_SPEED / 2
    static constexpr float GRAVITY{980.f};
    static constexpr float JUMP_TAKEOFF_SPEED{GRAVITY / 6.f};
    static constexpr float TIME_TO_SPAWN_LOGS{1.5f};
    static constexpr int MEDIUM_TEXT_SIZE{18};
    static constexpr int HUGE_TEXT_SIZE{56};
    static constexpr int FLAPPY_TEXT_SIZE{28};
    static constexpr float SEEDS_SIDE{30.f};
    static constexpr int SEEDS_TIME{15};
    static constexpr int POWER_TIME{Settings::SEEDS_TIME / 2};

    static std::unordered_map<std::string, sf::Texture> textures;
    static std::unordered_map<std::string, sf::SoundBuffer> sound_buffers;
    static std::unordered_map<std::string, sf::Sound> sounds;
    static std::unordered_map<std::string, sf::Font> fonts;

    static sf::Music music;
    static sf::Music music_power;

    static void init();

    static void load_textures();

    static void load_sounds();

    static void load_fonts();
};
