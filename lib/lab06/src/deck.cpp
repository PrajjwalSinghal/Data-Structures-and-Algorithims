//#include "../inc/deck.h"
//#include <fstream>
//#include <random>
//#include <ctime>
///* NOTE THIS CLASS WILL BE FINISHED FOR YOU, YOU DO NOT NEED TO WRITE ANY CODE FOR THIS CLASS*/
//
//const int BUFFER_SIZE = 500;
//
//deck::deck()=default;
//
//deck::deck(std::string rules, std::string deck_list) {
//
//}
//
//std::vector<std::string> deck::load(std::string file) {
//    std::ifstream in_file(file);
//    std::vector<std::string> input_parse;
//    char temp[BUFFER_SIZE];
//
//    while(in_file.good()) {
//        in_file.getline(temp, BUFFER_SIZE, ',');
//        input_parse.emplace_back(temp);
//    }
//    return input_parse;
//}
//
//void deck::riffle_shuffle() {
//    /* RANDOM NUMBER GENERATION CODE */
//    std::mt19937 simple_rand; // Setup random number generator
//    simple_rand.seed((unsigned)std::time(nullptr)); // Use for 'actual' random number generation
//    //simple_rand.seed(42); // USE FOR DEBUGGING RANDOM!
//
//    unsigned middle= int(abs(cards.get_size()/2 +(simple_rand()%20-10)))%cards.get_size();
//    doubly_linked_list right_cards= cards.split_before(middle),left_cards= cards,merged_cards ;
//    unsigned from_left=left_cards.get_size()-1, to_left=left_cards.get_size()-1,
//            from_right=right_cards.get_size()-1, to_right=right_cards.get_size()-1, riffle_count;
//
//    while(to_left > 0 || from_right > 0){
//        riffle_count=(unsigned)abs(simple_rand()%4+1);
//        from_left= (from_left < riffle_count)? 0: from_left-riffle_count;
//        riffle_count=(unsigned)abs(simple_rand()%4+1);
//        from_right= (from_right-riffle_count < 0)? 0: from_right-riffle_count;
//
//        if(to_left > 0 && from_right > 0){
//            merged_cards=merged_cards+ left_cards.split_set(from_left,to_left);
//            merged_cards=merged_cards+ right_cards.split_set(from_right,to_right);
//        }
//        else if(to_left > 0){
//            from_left=0;
//            merged_cards=merged_cards+ left_cards.split_set(from_left,to_left);
//        }
//        else{
//            from_right=0;
//            merged_cards=merged_cards+ right_cards.split_set(from_right,to_right);
//        }
//        to_left=from_left;
//        from_right=to_right;
//    }
//    cards=merged_cards;
//}
//
//void deck::overhand_shuffle() {
//    /* RANDOM NUMBER GENERATION CODE */
//    std::mt19937 simple_rand; // Setup random number generator
//    simple_rand.seed((unsigned)std::time(nullptr)); // Use for 'actual' random number generation
//    //simple_rand.seed(42); // USE FOR DEBUGGING RANDOM!
//
//    doubly_linked_list merge_deck;
//    unsigned from, card_count;
//    while(!cards.is_empty()){
//        card_count=(unsigned)simple_rand()%7;
//        from= cards.get_size() < card_count? 0 : (cards.get_size()-card_count);
//        merge_deck = cards.split_before(from);
//    }
//    cards=merge_deck;
//}
//
//// Draw a single card off of the top
//deck deck::draw(unsigned number_of_cards = 1) {
//    doubly_linked_list temp; // Create a temp variable to store the right hand side of the split
//    temp = cards.split_before(0+number_of_cards);
//
//    deck return_deck = deck(); // Create new deck to return;
//    return_deck.card_rules = card_rules; // Copy the card rules into return deck
//    return_deck.cards = cards; // Set the return deck to the current deck which is the left side of the split
//
//    cards = temp; // Copy the right hand side back into temp.
//
//    return return_deck;
//}
//
//// Pull a single or multiple cards out of the deck from any location
//deck deck::pull(unsigned position, unsigned number_of_card = 1) {
//    deck return_deck = deck(); // Create new deck to return
//    return_deck.card_rules = card_rules; // Copy the card rules into return deck
//    return_deck.cards = cards.split_set(position, position+number_of_card-1); // Copy the card into the new deck
//    return return_deck;
//}
//
//// Return bottom half of deck when split
//deck deck::split(unsigned position) {
//    deck return_deck = deck(); // Create new deck to return;
//    return_deck.card_rules = card_rules; // Copy the card rules into return deck
//    return_deck.cards = cards.split_after(position); // Split cards at input position and store it in new deck
//    return return_deck;
//}
//
//deck deck::operator+(const deck &rhs) const {
//    deck return_deck; // Create deck used to return
//    return_deck.cards = this->cards + rhs.cards; // Merge all of the cards together
//    return_deck.card_rules = this->card_rules; // Set the rules of the new deck to the left hand side
//    return_deck.card_rules.insert(rhs.card_rules.begin(), rhs.card_rules.end()); // Merge in the right rules
//    return return_deck;
//}
//
//deck &deck::operator=(const deck &rhs) {
//    this->cards = rhs.cards;
//    this->card_rules = rhs.card_rules;
//    return *this;
//}
//
//deck &deck::operator+=(const deck &rhs) {
//    this->cards += rhs.cards;
//    this->card_rules.insert(rhs.card_rules.begin(), rhs.card_rules.end());
//    return *this;
//}
//
//std::vector<deck> deck::deal(unsigned number_of_players, unsigned number_of_cards) {
//    std::vector<deck> player_hands;
//
//    player_hands.resize(number_of_cards);
//    for (int i = 0; i < number_of_cards; ++i) {
//        for (int j = 0; !cards.is_empty() && j < number_of_players; ++j) {
//            player_hands[j].draw(1);
//        }
//    }
//    return player_hands;
//}
//
//void deck::burn() {
//    cards.remove(0);
//}
//
//std::string deck::check_card(unsigned position) {
//    return card_rules[cards.get_data(position)];
//}
//
//std::ostream &operator<<(std::ostream &stream, const deck rhs) {
//    deck temp = rhs;
//    for (unsigned i = 0; i < temp.size(); ++i) {
//        stream << temp.card_rules[temp.cards.get_data(i)];
//    }
//    stream.flush();
//    return stream;
//}
//
//unsigned deck::size() {
//    return cards.get_size();
//}
//
