class Solution:
    def separateSquares(self, s: List[List[int]]) -> float:
        p = []
        i = 0
        while i < len(s):
            x, l = s[i][0], s[i][2]
            p.extend([x, x + l])
            i += 1
        
        p = sorted(list(set(p)))
        n = len(p)
        
        class E:
            def __init__(self, y, t, l, r):
                self.y = y
                self.t = t
                self.l = l
                self.r = r
        
        v = []
        i = 0
        while i < len(s):
            x, y, l = s[i][0], s[i][1], s[i][2]
            a = bisect.bisect_left(p, x)
            b = bisect.bisect_left(p, x + l)
            v.append(E(y, 1, a, b))
            v.append(E(y + l, -1, a, b))
            i += 1
        
        v.sort(key=lambda e: (e.y, -e.t))
        
        z = 4 * n
        c = [0] * z
        d = [0.0] * z
        
        def u(i, l, r, a, b, v):
            if a >= r or b <= l:
                return
            if a <= l and r <= b:
                c[i] += v
            else:
                m = (l + r) // 2
                u(i * 2, l, m, a, b, v)
                u(i * 2 + 1, m, r, a, b, v)
            
            if c[i] > 0:
                d[i] = p[r] - p[l]
            else:
                if r - l == 1:
                    d[i] = 0.0
                else:
                    d[i] = d[i * 2] + d[i * 2 + 1]
        
        class S:
            def __init__(self, s, e, x, c):
                self.s = s
                self.e = e
                self.x = x
                self.c = c
        
        w = []
        y = 0.0
        a = 0.0
        k = 0.0
        i = 0
        j = len(v)
        
        if j > 0 and v[0].y > 0.0:
            w.append(S(0.0, v[0].y, 0.0, a))
            a += 0.0 * (v[0].y - 0.0)
            y = v[0].y
        else:
            y = 0.0
        
        while i < j:
            q = v[i].y
            if q > y:
                w.append(S(y, q, k, a))
                a += k * (q - y)
                y = q
            
            while i < j and abs(v[i].y - q) < 1e-12:
                u(1, 0, n, v[i].l, v[i].r, v[i].t)
                i += 1
            
            k = d[1]
        
        t = a
        h = t / 2.0
        r = 0.0
        
        i = 0
        while i < len(w):
            g = w[i]
            x = g.x * (g.e - g.s)
            
            if h <= g.c + 1e-12:
                r = g.s
                break
            if g.c < h and h <= g.c + x + 1e-12:
                if abs(g.x) < 1e-12:
                    r = g.s
                else:
                    o = (h - g.c) / g.x
                    r = g.s + o
                break
            i += 1
        
        return r