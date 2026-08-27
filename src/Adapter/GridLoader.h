//
// Created by aleks on 22.06.2026.
//

#ifndef CPP_GRIDLOADER_H
#define CPP_GRIDLOADER_H

#include <string>
#include <nlohmann/json.hpp>

#include "../Simulation/Maze.h"

/**
 * @defgroup AdapterModule Adapter
 * @brief Adapter class for reading files
 */

/**
 * @ingroup AdapterModule
 * @file GridLoader.h
 * @brief Functions for loading maze data from JSON files.
 */

/**
 * @brief Checks if a string contains a given character. Used for Maze walls detecting.
 *
 * @param s The string to search through.
 * @param c The character to look for.
 * @return True if the character is found, false otherwise.
 */
bool has(const std::string& s, char c);

/**
 * @brief Parses a JSON object into a MazeCell.
 *
 * Used by the nlohmann::json library to automatically
 * convert JSON data into MazeCell objects.
 *
 * @param j The JSON object to read from.
 * @param value The MazeCell to populate with parsed data.
 */
void from_json(const nlohmann::json& j, MazeCell& value);

/**
 * @brief Loads a maze from a JSON file.
 *
 * Reads the file at the given path and constructs a Maze
 * object with the specified dimensions.
 *
 * @param path Path to the JSON file.
 * @param w Width of the maze in cells.
 * @param h Height of the maze in cells.
 * @return The loaded Maze object.
 */
Maze loadMaze(const std::string& path, int w, int h);

/**
 * @brief Loads the maze file path from the configuration.
 *
 * @return A string containing the path to the maze file.
 */
std::string loadPath();

/**
 * @brief Loads the algorithm name from a configuration file.
 *
 * @param path Path to the configuration file.
 * @return The name of the algorithm to use for solving.
 */
std::string loadAlgorithm(const std::string& path);

/**
 * @brief Loads the maze width from a configuration file.
 *
 * @param path Path to the configuration file.
 * @return Width of the maze in cells.
 */
int loadWidth(const std::string& path);

/**
 * @brief Loads the maze height from a configuration file.
 *
 * @param path Path to the configuration file.
 * @return Height of the maze in cells.
 */
int loadHeight(const std::string& path);

/**
 * @brief Validates that the grid dimensions match the cell data.
 *
 * Checks if the given width and height are consistent with
 * the actual size of the 2D cell vector. Throws an exception
 * if there is a mismatch.
 *
 * @param w Expected width.
 * @param h Expected height.
 * @param cells The 2D grid of maze cells to validate.
 */
void validateGrid(int w, int h, const std::vector<std::vector<MazeCell>>& cells);

#endif //CPP_GRIDLOADER_H
