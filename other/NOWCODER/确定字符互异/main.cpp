class Different
{
public:
	bool checkDifferent(string iniString)
	{	
		// write code here
		for(int i=0;i<iniString.length();++i)
		{
			for(int j=i-1;j>=0;--j)
			{
				if(iniString[j]==iniString[i])
					return false;
			}
		}
		return true;
	}
};