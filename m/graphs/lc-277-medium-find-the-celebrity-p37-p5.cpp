/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        unordered_set<int> universe;
        for (int i = 0; i < n; ++i)
            universe.insert(i);

        while (universe.size() > 1) {
            int candidate = *universe.begin();
            universe.erase(candidate);
            unordered_set<int> new_universe;
            bool candidate_knows_someone = false;
            for (auto x: universe) {
                cout << "candidate, x = " << candidate << ", " << x << endl;
                if (knows(candidate, x)) {
                    candidate_knows_someone = true;
                    new_universe.insert(x);
                } else {
                    //
                }
            }
            if (candidate_knows_someone == false) {
                new_universe.insert(candidate);
            }
            universe = new_universe;
        }
        
        int last_one = *universe.begin();
        
        for (int i = 0; i < n; ++i) {
            if (i == last_one)
                continue;
            if (!knows(i, last_one))
                return -1;
            if (knows(last_one, i))
                return -1;
        }
        return last_one;
    }
};

