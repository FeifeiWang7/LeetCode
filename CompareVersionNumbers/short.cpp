I'm not sure it is good idea to use such classes that help parsing strings in an interview because it makes the solution looks too simple. Anyway, I'm going to share my solution.

int compareVersion(string version1, string version2) {
    istringstream iss1(version1), iss2(version2);
    string token1, token2;

    while(!iss1.eof() || !iss2.eof()) {
        getline(iss1, token1, '.'); getline(iss2, token2, '.');

        if(stoi(token1) > stoi(token2)) return 1;
        if(stoi(token1) < stoi(token2)) return -1;

        token1 = token2 = "0";
    }

    return 0;
}
