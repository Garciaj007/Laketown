#ifndef  IFILETYPE_H
#define  IFILETYPE_H

class IFileType
{
public:
	virtual void createFile() = 0;
	virtual void WriteFile() = 0;
};
#endif // ! IFILETYPE_H

