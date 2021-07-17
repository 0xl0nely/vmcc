/*
Create a finite automaton that has three states. Finite automatons are the same as finite state machines for our purposes.

Our simple automaton, accepts the language of A, defined as {0, 1} and should have three states: q1, q2, and q3. Here is the description of the states:

    q1 is our start state, we begin reading commands from here
    q2 is our accept state, we return true if this is our last state

And the transitions:

    q1 moves to q2 when given a 1, and stays at q1 when given a 0
    q2 moves to q3 when given a 0, and stays at q2 when given a 1
    q3 moves to q2 when given a 0 or 1

The automaton should return whether we end in our accepted state (q2), or not (true/false).

You will have to design your state objects, and how your Automaton handles transitions. 
Also make sure you set up the three states, q1, q2, and q3 for the myAutomaton instance. 
The test fixtures will be calling against myAutomaton.

As an aside, the automaton accepts an array of strings, rather than just numbers, or a number 
represented as a string, because the language an automaton can accept isn't confined to just numbers. 
An automaton should be able to accept any 'symbol.'
*/

#include <bits/stdc++.h>
class Automaton {
private:
    enum state{q1, q2, q3};
    state current_state = q1;
public:
    Automaton() {}
    bool read_commands(const std::vector<char>& commands) {
        int v_size = commands.size(), i;
        for (i = 0; i < v_size; i++) {
            switch(current_state) {
            case q1: (commands[i] == 0x31) ? current_state = q2 : current_state = q1;break;
            case q2: (commands[i] == 0x30) ? current_state = q3 : current_state = q2;break;
            case q3: if (commands[i]) current_state = q2;break;
            }
        }
    return (current_state == q2);
    }
};

int main(int argc, char**argv) {
    Automaton a;
    std::vector<char> test1{'1', '0','0','1'}, test2{'1'};
    a.read_commands(test1);
    a.read_commands(test2);
}
