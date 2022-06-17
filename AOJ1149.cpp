#include <iostream>
#include <vector>
#include <algorithm>

struct Segment {
    int depth;
    int width;
    int area;
};

std::vector<int> origin(int depth, int width, int s)
{
    std::vector<int> ret(2);

    s %= (2 * (width + depth));
    if (s < 0) {
        s += 2 * (width + depth);
    }

    if (s <= width) {
        ret[0] = 0;
        ret[1] = s;
    } else if (s <= width + depth) {
        ret[0] = s - width;
        ret[1] = width;
    } else if (s <= 2 * width + depth) {
        ret[0] = depth;
        ret[1] = 2 * width + depth - s;
    } else {
        ret[0] = 2 * (width + depth) - s;
        ret[1] = 0;
    }

    return ret;
}

int main()
{
    int n, w, d, i, j, p, s;
    std::vector<int> start(2);
    auto seg_comp = [](Segment &seg1, Segment &seg2) {
        return seg1.area < seg2.area;
    };
    
    while (true) {
        std::cin >> n >> w >> d;
        if (n == 0 && w == 0 && d == 0) {
            break;
        }
        
        if (n == 0) {
            std::cout << d * w << std::endl;
            continue;
        }

        std::vector<Segment> vs;
        Segment seg = {d, w, d * w};
        vs.emplace_back(seg);
        for (i = 0; i < n; i++) {
            std::cin >> p >> s;
            start = origin(vs[p - 1].depth, vs[p - 1].width, s);

            Segment seg1, seg2;
            if (start[0] == 0 || start[0] == vs[p - 1].depth) {
                seg1 = {vs[p - 1].depth, start[1], vs[p - 1].depth * start[1]};
                seg2 = {vs[p - 1].depth, vs[p - 1].width - start[1], vs[p - 1].depth * (vs[p - 1].width - start[1])};
            } else {
                seg1 = {start[0], vs[p - 1].width, start[0] * vs[p - 1].width};
                seg2 = {vs[p - 1].depth - start[0], vs[p - 1].width, (vs[p - 1].depth - start[0]) * vs[p - 1].width};
            }

            for (j = p; j < vs.size(); j++) {
                vs[j - 1] = vs[j];
            }
            if (seg1.area >= seg2.area) {
                vs[vs.size() - 1] = seg2;
                vs.emplace_back(seg1);
            } else {
                vs[vs.size() - 1] = seg1;
                vs.emplace_back(seg2);
            }
        }

        std::sort(vs.begin(), vs.end(), seg_comp);
        for (i = 0; i < vs.size() - 1; i++) {
            std::cout << vs[i].area << " ";
        }
        std::cout << vs[vs.size() - 1].area << std::endl;
    }

    return 0;
}