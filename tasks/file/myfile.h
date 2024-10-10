#ifndef FILE_H
#define FILE_H

typedef struct {
    char str[11];
} Date;

void createFileIntRnd(int from, int to, int number, const char* file_name);
void createFileDoubleRnd(int from, int to, int number, const char* file_name);
void showFileNumInt(const char* file_name);
void showFileNumDouble(const char* file_name);
void showCharFile(const char* name);
void showFileOfStrings(const char* file_name);
void showFileOfChar(const char* file_name);
int quantityIntInFile(const char* file_name);
int quantityDoubleInFile(const char* file_name);
int getFileLengthInBytes(const char* file_name);
int getIntElemFromFile(const char* file_name, int pos);
double getDblElemFromFile(const char* file_name, int pos);
void createEmptyFile(const char* file_name);
void writeDblElemInFile(const char* file_name, double elem, int pos);
void addIntElemInExistFile(const char* file_name, int elem, int pos);
void addDblElemInExistFile(const char* file_name, double elem, int pos);
int is_local_min_dbl(const char* file_name, int n, int pos);
void is_local_min_dbl_better(const char* file_name, const char* file_name_pos);
void is_local_max_dbl_better(const char* file_name, const char* file_name_pos);
int is_local_max_dbl(const char* file_name, int n, int pos);
void swapIntElemInFile(const char* file_name, int i, int j);
int fileCopy(const char* src, const char* dst);
int fileCopyFast(const char* src, const char* dst);
int fileCopyFastAddInEnd(const char* src, const char* dst);
void sortFile(const char* file_name);
int getPosMinInDblFile(const char *file_name, double *min_value);
void CopyDouleFileExceptPos(const char* src, const char* dst, int pos);
void sortIncDblFile(const char* file_name);
void mergeTwoSortedIncDblFiles(const char* src_1, const char* src_2, const char* dst);
void revDblFile(const char* file_name);
void sortIncDblFileWithSeek(const char* file_name);
void createEmptyFile(const char* file_name);
void addToEndIntFileToArchive(const char* src, const char* dst);
void addToEndDblFileToArchive(const char* src, const char* dst);
int getAmountOfIntFilesArchive(const char* file);
int getAmountOfDblFilesArchive(const char* file);
void getIntFileFromArchive(const char* src, int num, const char* dst);
void getDblFileFromArchive(const char* src, int num, const char* dst);
void deleteIntFileFromArchive(const char* file, int num);
void deleteDblFileFromArchive(const char* file, int num);
void insertIntFileToArchive(const char* dst, int num, const char* src);
void insertDblFileToArchive(const char* dst, int num, const char* src);
void addToEndIntElemToFile(const char* file, int elem);
void addToEndDblElemToFile(const char* file, double elem);
void createA55(int n, const char* arh_name);
void createCharFile(const char* name, int n, int from, int to);
int is_Space(int c);
void sortIncIntFileSymbolsWithSeek(const char* file_name);
void createFileOfStrings(const char* file_name, int from, int to, int num_str, int str_len);
void createFileOfStringsWithRandLength(const char* file_name, int from, int to, int num_str, int str_len);
char getCharByPosInString(const char* s, int pos);
void sortIncStringFileWithSeek(const char* file_name);
void sortIncStringByLengthFileWithSeek(const char* file_name);
void sortStringsFileOfDatasWithSeek(const char* file_name);
void revStringFile(const char* file_name);
void createStringData(char* str_data, int day, int month, int year);
void createStringOfRandData(char* str_data, int from_year, int to_year);
void createFileOfRandData(const char* file_name, int num_str, int from_year, int to_year);
int getDay(char* str_data);
int getMonth(char* str_data);
int getYear(char* str_data);


Date createDate(int d, int m, int y);
Date createDateRND();
void showDate(Date date);
void showDateLn(Date date);
int getDay2(Date date);
int getMonth2(Date date);
int getYear2(Date date);
Date setDay(const Date date, int day);
Date setMonth(const Date date, int month);
Date setYear(const Date date, int year);
int cmpDates(Date d1, Date d2);
void createFileOfRandData2(const char* file_name, int num_str, int from_year, int to_year);
void showFileOfDateLn(const char* file_name);
void sortDecStringsFileOfDatasWithSeek2(const char* file_name);

void createFileOfDblRndMatr(const char* fname, int m, int n, int from, int to);
void showFileOfDblMatr(const char* fname);
double getElemOfFileMatr(const char* fname, int i, int j);
void getSizeOfMatr(const char* fname, int *m, int *n);
void transpositionFileOfDblMatr(const char* fname);
void setElemToExistFileMatr(const char* fname, int i, int j, double elem);
void zeroMainDiagonalM(const char* fname, int d);
void createFileWithHighTriagleMatr(const char* fname, int m, int n, int from, int to);
void createFileWithLowTriagleMatr(const char* fname, int m, int n, int from, int to);
void createFileWithThreeDiagMatr(const char* fname, int m, int n, int from, int to);





#endif // FILE_H
