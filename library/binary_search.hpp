// v 中に t を見つけたら そのindex 、なければ -1を返す
int binsearch(vector<int> v, int t) {
    int l = 0, r = v.size(); // 最初は全範囲 (半開区間)
    while (l+1 < r) { // 範囲の長さが 0 でない限り繰り返す
        int m = l + (r - l) / 2; // 中間の点...オーバーフロー対策の式
        // 中間点で一致した = 見つかった
        if (v[m] == t) return m;
        // 見つからなかったら、値の大小に応じて範囲を狭める
        if (v[m] < t) l = m;
        else          r = m;
    }
    // ここまできたら見つからなかった → v中にない
    return -1;
}