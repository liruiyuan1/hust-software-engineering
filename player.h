#ifndef RICH_PLAYERS_H
#define RICH_PLAYERS_H
#include <cstdint>
#include <vector>


enum Color { RED, GREEN, BLUE, YELLOW };
// 玩家索引
enum PlayerIdx { NONE, PQ, PA, PS, PJ };

typedef struct player {
    char uid;
    std::string name;
    std::uint64_t n_money;
    std::uint64_t n_points;
    std::uint8_t n_pos;
    std::uint8_t n_empty_rounds;
    std::uint8_t n_god_buff;
    color_t e_color;
    std::vector<p_map_node_t> estate;
    std::uint8_t n_block;
    std::uint8_t n_boom;
    std::uint8_t n_robot;
} player_t, *p_player_t;


#endif //RICH_PLAYERS_H
