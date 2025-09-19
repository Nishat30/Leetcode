class Spreadsheet {
    unordered_map<string, int> map;

public:
    Spreadsheet(int rows) { }

    void setCell(string cell, int value) {
        map[cell] = value;
    }

    void resetCell(string cell) {
        map.erase(cell);
    }

    int getValue(string formula) {
        int pos = formula.find('+');
        string cell1 = formula.substr(1, pos - 1);
        string cell2 = formula.substr(pos + 1);

        int val1 = isalpha(cell1[0]) ? (map.count(cell1) ? map[cell1] : 0) : stoi(cell1);
        int val2 = isalpha(cell2[0]) ? (map.count(cell2) ? map[cell2] : 0) : stoi(cell2);

        return val1 + val2;
    }
};