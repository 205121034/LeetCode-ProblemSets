class Solution {
    public int minimumPairRemoval(int[] arr) {
        int n = arr.length;

        class Node {
            long val;
            int prev, next, ver;
            boolean active;

            Node(long val, int prev, int next) {
                this.val = val;
                this.prev = prev;
                this.next = next;
                this.ver = 0;
                this.active = true;
            }
        }

        Node[] nodes = new Node[n];
        int k = 0;
        while (k < n) {
            nodes[k] = new Node(arr[k], k - 1, k + 1);
            k++;
        }

        if (n > 0) nodes[n - 1].next = -1;

        class Entry {
            long sum;
            int idx, ver;

            Entry(long sum, int idx, int ver) {
                this.sum = sum;
                this.idx = idx;
                this.ver = ver;
            }
        }

        PriorityQueue<Entry> pq = new PriorityQueue<>((a, b) -> {
            if (a.sum == b.sum) return Integer.compare(a.idx, b.idx);
            return Long.compare(a.sum, b.sum);
        });

        int i = 0;
        while (i < n) {
            if (nodes[i].next != -1) {
                int nxt = nodes[i].next;
                pq.offer(new Entry(nodes[i].val + nodes[nxt].val, i, nodes[i].ver));
            }
            i++;
        }

        int inversions = 0;
        int idx = 0;
        while (idx < n) {
            int nxt = nodes[idx].next;
            if (nxt != -1 && nodes[idx].val > nodes[nxt].val) inversions++;
            idx++;
        }

        int ops = 0;

        while (inversions > 0) {
            Entry current = null;
            boolean valid = false;

            while (!pq.isEmpty()) {
                Entry top = pq.poll();
                int pos = top.idx;

                if (pos < 0 || pos >= n || !nodes[pos].active) continue;
                if (nodes[pos].ver != top.ver) continue;

                int nxt = nodes[pos].next;
                if (nxt == -1 || !nodes[nxt].active) continue;

                long total = nodes[pos].val + nodes[nxt].val;
                if (total != top.sum) continue;

                current = top;
                valid = true;
                break;
            }

            if (!valid) break;

            int a = current.idx;
            int b = nodes[a].next;
            int before = nodes[a].prev;
            int after = nodes[b].next;
            long combined = nodes[a].val + nodes[b].val;

            int oldInv = 0;
            if (before != -1 && nodes[before].val > nodes[a].val) oldInv++;
            if (nodes[a].val > nodes[b].val) oldInv++;
            if (after != -1 && nodes[b].val > nodes[after].val) oldInv++;

            int newInv = 0;
            if (before != -1 && nodes[before].val > combined) newInv++;
            if (after != -1 && combined > nodes[after].val) newInv++;

            inversions = inversions - oldInv + newInv;

            nodes[a].val = combined;
            nodes[a].ver += 1;
            nodes[b].active = false;
            nodes[a].next = after;

            if (after != -1) nodes[after].prev = a;

            if (before != -1 && nodes[before].active) {
                pq.offer(new Entry(nodes[before].val + nodes[a].val, before, nodes[before].ver));
            }

            if (after != -1 && nodes[a].active) {
                pq.offer(new Entry(nodes[a].val + nodes[after].val, a, nodes[a].ver));
            }

            ops++;
        }

        return ops;
    }
}
