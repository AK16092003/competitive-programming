class medianset
{	
public:
	int n;
	multiset<int> s1;
	multiset<int> s2;

	void insert(int x)
	{
		if(s1.size() == 0)
		{
			s1.insert(x);
			return;
		}
		if(s1.size() > s2.size())
		{
			if(*(s1.rbegin()) > x)
			{
				// insert x in s1
				s1.insert(x);
				int val = *(s1.rbegin());
				s1.erase(s1.find(val));
				s2.insert(val);
			}
			else
			{
				// insert x in s2
				s2.insert(x);
			}
		}
		else
		{
			if(*(s1.rbegin()) <= x)
			{
				// insert x in s1
				s2.insert(x);
				int val = *(s2.begin());
				s2.erase(s2.find(val));
				s1.insert(val);
			}
			else
			{
				// insert x in s2
				s1.insert(x);
			}
		}
	}

	void erase(int x)
	{
		if(s1.find(x)!=s1.end())
		{
			s1.erase(s1.find(x));
			if(s1.size() < s2.size())
			{
				int val = *(s2.begin());
				s2.erase(s2.find(val));
				s1.insert(val);
			}
		}
		else
		{
			s2.erase(s2.find(x));
			if(s2.size() == s1.size()-2)
			{
				int val = *(s1.rbegin());
				s1.erase(s1.find(val));
				s2.insert(val);
			}
		}
	}

	int getmedian()
	{
		return *(s1.rbegin());
	}
};
