func isAnagram(s string, t string) bool {
    mp:= make(map[rune]int)
    for _,c:=range s{
        mp[c]++
    }
    for _,c:=range t{
        mp[c]--
        if mp[c] == 0 {
            delete(mp, c) // remove key when count is zero
        }
    }
    if len(mp)==0{
        return true
    }
    return false
}