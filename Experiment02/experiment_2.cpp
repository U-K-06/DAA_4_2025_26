#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *l, *r;
    Node(char c, int f) {
        ch = c;
        freq = f;
        l = r = nullptr;
    }
};

struct HeapCmp {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void generate(Node* root, string code,
              unordered_map<char,string>& enc,
              unordered_map<string,char>& dec) {
    if (!root) return;
    if (!root->l && !root->r) {
        enc[root->ch] = code;
        dec[code] = root->ch;
    }
    generate(root->l, code + "0", enc, dec);
    generate(root->r, code + "1", enc, dec);
}

string decode(const string& encoded,
              unordered_map<string,char>& dec) {
    string curr, res;
    for (char c : encoded) {
        curr += c;
        if (dec.count(curr)) {
            res += dec[curr];
            curr.clear();
        }
    }
    return res;
}

void huffman(string s) {
    unordered_map<char,int> freq;
    for (char c : s) freq[c]++;

    priority_queue<Node*, vector<Node*>, HeapCmp> pq;
    for (auto &x : freq)
        pq.push(new Node(x.first, x.second));

    while (pq.size() > 1) {
        Node* a = pq.top(); pq.pop();
        Node* b = pq.top(); pq.pop();
        Node* p = new Node('#', a->freq + b->freq);
        p->l = a;
        p->r = b;
        pq.push(p);
    }

    unordered_map<char,string> encodeMap;
    unordered_map<string,char> decodeMap;
    generate(pq.top(), "", encodeMap, decodeMap);

    cout << "Huffman Codes:\n";
    for (auto &x : encodeMap)
        cout << x.first << ": " << x.second << endl;

    string encoded;
    for (char c : s)
        encoded += encodeMap[c];

    cout << "\nEncoded String: " << encoded << endl;
    cout << "Decoded String: " << decode(encoded, decodeMap) << endl;
}

int main() {
    string s;
    cin >> s;
    huffman(s);
    return 0;
}
