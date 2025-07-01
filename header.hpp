#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

#define NUMBER_OF_TEAMS 2
#define ZERO 0
#define NUMBER_OF_POSITIONS 4
#define MAX_PLAYERS_OF_FANTASY_TEAM 5
#define GOALKEEPER 1
#define DEFENDER 2
#define MIDFIELDER 3
#define FORWARD 4
#define NOT_FOUND -1
#define TEAM_1 1
#define MAX_INJURY_WEEKS 3
#define MAX_YELLOW_CARDS 3
#define MAX_RED_CARDS 1
#define WIN_POINT 3
#define LOSE_POINT 0
#define EQUAL_POINT 1

class Player
{
public:
    Player(string _name, int _position);
    int get_position();
    void save_score(float score);
    string get_name();
    vector<float> get_score();
    bool is_in_this_position(int _position);
    void save_injury();
    void save_yellow_cards();
    void save_red_cards();
    void change_score(string _score);
    bool check_yellow_cards();
    bool check_red_cards();
    void set_availablitiy();
    bool is_player_available();
    bool check_injury();
    float get_average_score();

private:
    string name;
    int position;
    vector<float> score;
    int yellow_cards;
    int red_cards;
    bool injury;
    int injury_weeks;
    bool is_available;
};

class Real_Team
{
public:
    void save_result(int _goals, int _no_goals);
    int find_player_position(string name);
    int get_game_point(int week_number);
    int get_total_goals();
    int get_total_no_goals();
    bool have_the_player(string name);
    void save_score_player(string name, string score);
    string get_team_name();
    vector<Player *> get_all_players_of_team();
    void save_injured_player(string name);
    void save_yellow_card_player(string name);
    void save_red_card_player(string name);
    void set_members_name(string _team_name, vector<string> players_name, int players_position);
    void print();
    int get_total_score();
    int get_tafazol();
    int get_goals_in_week(int week_number);
    Player *find_player_by_name(string name);

private:
    string team_name;
    vector<int> goals;
    vector<int> no_goals;
    vector<Player *> team_players;
};

class game_data
{
public:
    void set_injured_players(vector<string> injured_players);
    void set_players_score(vector<string> players_score);
    void set_yellow_cards(vector<string> yellow_card_players);
    void set_red_cards(vector<string> red_card_players);
    int find_the_team_contains_player(string name);
    game_data(Real_Team *_team_1, Real_Team *_team_2);
    void set_result(vector<string> results);
    vector<vector<string>> seperate_players_scores(vector<string> players_scores);
    Real_Team *get_team_1();
    Real_Team *get_team_2();
    void print();

private:
    Real_Team *team_1;
    Real_Team *team_2;
};

class User_Team
{
public:
    User_Team(string _team_name, string _password);
    bool is_team_full();
    string get_name();
    void login();
    bool check_password_correctness(string _password);
    void logout();
    bool is_login();
    void delete_player(Player *player);
    int find_index_player(Player *player);
    void add_player(Player *player);
    void update_points(int week_number);
    bool does_team_have_free_space(int position);
    int number_of_players_in_position(int position);
    float get_team_point();
    vector<Player *> get_players();
    void check_is_ready();
    bool is_ready();
    bool check_no_duplicate_buy(Player *player);
    void save_last_arrange();
    vector<Player *> get_last_players();
    void ready_for_competition();

private:
    vector<Player *> players;
    vector<Player *> last_players;
    string password;
    string team_name;
    int number_of_sales;
    float team_point;
    bool is_user_login;
    bool is_team_ready;
    bool is_team_join_competition;
};

class Week
{
public:
    Week(vector<game_data *> games);

    void push_back_game(game_data *game_data);

    vector<game_data *> get_game_data();

private:
    vector<game_data *> games_data;
};

class Admin
{
public:
    Admin(string, string);
    bool is_admin_online();
    void do_resgister(string _username, string _password);
    void logout();

private:
    bool is_online;
    string user_name;
    string password;
};

class Futball
{
public:
    Futball(Admin *admin);
    bool check_user_team_existence(string team_name);
    bool check_real_team_existence(string team_name);
    string make_team_name(string team_name);
    void close_transfer_window();
    void open_transfer_window();
    void logout();
    void buy_player();
    void register_admin();
    User_Team *find_user_team_by_name(string team_name);
    int find_the_chosen_week(vector<string> order_words);
    void sort_teams_by_their_score();
    void sort_teams_by_their_tafazol(Real_Team **team_1, Real_Team **team_2);
    void sort_teams_by_their_goals(Real_Team **team_1, Real_Team **team_2);
    void print_league_standings();
    void matches_result_league();
    string find_team_name();
    bool is_anybody_online();
    void print_matches_result(int week_number);
    void check_players_absence();
    int get_first_comma_index(string &line);
    vector<string> read_input(string line);
    void print();
    void pass_week();
    void print_users_ranking();
    game_data *make_game(vector<string> teams_name);
    void make_team_of_the_week();
    void get_orders(string order);
    void post_orders(string order);
    void signup();
    void login();
    void make_user_team();
    void print_user_team(vector<Player *> players, User_Team *user_team);
    void update_team_points();
    void read_order();
    void filter_players_of_team();
    bool check_duplicate_team_name(string name);
    void set_teams(string team_name, vector<string> players_name, int players_position, Real_Team *temp_team);
    void print_players_of_team(vector<Player *> sorted_players);
    vector<Player *> sort_players_by_their_rank(vector<Player *> players);
    vector<Player *> sort_players_by_their_rank_and_name(vector<Player *> players, int week_number);
    void get_players_of_team_by_position(Real_Team *team, int position, vector<Player *> &players_in_position);
    string convert_number_to_position_name(int position);
    vector<Player *> sort_players_by_their_name(vector<Player *> players_in_position);
    vector<Player *> find_max_score_player(vector<Player *> players, int week_number, int num_of_players);
    vector<vector<string>> put_players_in_positions(int position, vector<game_data *> games_data);
    int find_player_position_by_name(string name);
    Player *find_player_by_name(string name);
    void put_game_in_week(game_data *games_data);
    vector<User_Team *> sort_user_teams_by_their_points(vector<User_Team *> teams);
    void read_premier_leage_data();
    void read_one_week(string file_name);
    int change_position_name_to_int(string position);
    void make_position_of_the_week(int position, int number_of_players, int week_number, string position_name);
    void print_team_of_the_week(vector<Player *> max_score_player, string position_name, int week_number, int number_of_player);
    vector<Player *> seperate_players_position(int position);
    void set_team_players_score_with_zero(vector<string> teams_name);
    vector<int> find_first_5_commas(string line);
    Real_Team *find_team_by_name(string name);
    bool check_no_duplicate_player(Player *player_max, vector<Player *> players);
    vector<string> get_names(string &line, char spacer_charachter);
    User_Team *which_team_is_login();
    void sell_player();
    bool check_player_existence(string player_name);
    bool is_transfer_window_open();
    void set_players_availability();
    void check_ready_teams();
    void sort_players_by_their_position(vector<Player *> &players);
    void print_players_of_team(vector<Player *> players_int_position, vector<string> order_words);
    void delete_vectors();

private:
    vector<Week *> weeks;
    vector<Real_Team *> real_teams;
    vector<User_Team *> user_teams;
    int flag_transfer_window;
    bool is_user_online;
    Admin *admin;
};
