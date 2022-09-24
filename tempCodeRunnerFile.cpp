char isLowercase(char ch)
{
    if (ch > 64 && ch < 97)
    {
        return ch;
    }
    else
    {
        char ans = ch + 'A' - 'a';
        return ans;
    }
}