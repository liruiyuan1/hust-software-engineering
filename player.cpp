#include <map>
#include "player.h"


static vector<player_t> player_vec;

uint64_t init_money;


vector<player_t>* get_player_vec() {
    return &player_vec;
}


void add_player(char uid) {
    static std::map<char, string> player_names = {
            {'Q', "钱夫人"},
            {'A', "阿土伯"},
            {'S', "孙小美"},
            {'J', "金贝贝"}
    };
    static std::map<char, color_t> player_color = {
            {'Q', RED},
            {'A', GREEN},
            {'S', BLUE},
            {'J', YELLOW}
    };
    switch (uid) {
        default:
            return;
        case 'Q':
        case 'A':
        case 'S':
        case 'J':
            break;
    }
    player_t next_player;
    next_player.uid = uid;
    next_player.name = player_names[uid];
    next_player.n_points = 0;
    next_player.n_money = init_money;
    next_player.e_color = player_color[uid];
    next_player.n_block = 0;
    next_player.n_boom = 0;
    next_player.n_robot = 0;
    next_player.n_pos = 0;
    next_player.n_empty_rounds = 0;
    next_player.n_god_buff = 0;
    player_vec.push_back(next_player);
}


p_player_t get_player_by_uid(char uid) {
    for (auto &player : player_vec) {
        if (player.uid == uid) {
            return &player;
        }
    }
    return nullptr;
}


p_player_t skip_player(p_player_t next_player){
    if (next_player->n_money >= 0 && next_player->n_empty_rounds == 0) return next_player;
    else{
        char last_uid = next_player->uid;
        auto players = get_player_vec();
        for (auto & it : *players) {
            if (last_uid == it.uid) return &it;
            last_uid = it.uid;
        }
    }
    return nullptr;
}
