int ans = 0;     
        for(int i = n-1; i >= 0; i--) {
            auto it1 = m.find(a[i]);
            if(it1 == m.end()) continue;         
            auto it = m.find(a[i]-1);
            if(it != m.end()) {
                int oc = min(it->second,m[a[i]]);
                ans += a[i]*oc;
                m[a[i]] -= oc;
                m[a[i]-1] -= oc;
                if(m[a[i]] <= 0) m.erase(a[i]);
                if(m[a[i]-1] <= 0) m.erase(a[i]-1);
            }
            else {
                ans += a[i]*m[a[i]];
                m[a[i]] = 0;             
            }         
        }
        return ans;     
    }
