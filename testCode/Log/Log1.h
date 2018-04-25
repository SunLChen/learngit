#ifndef _LOG1_H_
#define _LOG1_H_
#include <iostream>
#include <fstream>
using std::string;
using std::fstream;
using std::ios;

class Clog{
	public:
		//设置log的等级
		enum LOG_LEVEL{
			LL_ERROR=1,
			LL_WARN=2,
			LL_INFORMATION=3
		};
	public:
		Clog(void)
			:m_openSuccess(false)
			 ,m_Loglevel(LL_ERROR)
			 ,m_showLogFlag(true)
			 ,m_maxLogFileSize(10*1024*1024)
			{};
		Clog(const char *filePath,LOG_LEVEL level=LL_ERROR);
		Clog(const wchar_t *filePath,LOG_LEVEL level=LL_ERROR);
		virtual ~Clog(void){
			if(m_openSuccess){
				CloseLogFile();
			}
		}
		//打开日志文件
		void OpenLogFile(const char *pFilePath,LOG_LEVEL level=LL_ERROR);
		void OpenLogFile(const wchar_t *pFilePath,LOG_LEVEL level=LL_ERROR);
		//写日志操作
		void writeLog(LOG_LEVEL level,const char * pLogText,...);
		void writeLog(string logText,LOG_LEVEL level=LL_ERROR);
		void writeLog(const char *pLogText,LOG_LEVEL level=LL_ERROR);
		void writeLogEx(LOG_LEVEL level,const char *pLogText,...);
		//得到日志文件的大小
		size_t GetLogFileSize();
		//清空日志文件内容
		void ClearLogFile();
		void CloseLogFile();

		void SetLoglevel(LOG_LEVEL level=LL_ERROR){
			m_Loglevel=level;
		}
		LOG_LEVEL GetLogLevel()const{
			return m_Loglevel;
		}

		void SetShowFlag(bool flag=true){
			m_showLogFlag=flag;
		}

		bool GetShowFlag()const
		{
			return m_showLogFlag;
		}

		void SetMaxLogFileSize(size_t size){
			m_maxLogFileSize=size;
		}

		size_t GetMaxLogFileSize(){
			return m_maxLogFileSize;
		}

		string &GetLogFilePath(){
			return m_logFilePath;
		}

		bool GetOpenStatus()const{
			return m_openSuccess;
		}
	protected:
		string W2A(const wchar_t *pWCsStr);//转string
		string ConverToRealLogText(const char *pLogText,LOG_LEVEL level=LL_ERROR);
		const std::string &StringFormat(std::string &srcString,const char *pFormatString,...);
	protected:
		fstream m_fileOut;
		bool m_openSuccess;//日志的打开状态，true表示成功打开
		string m_logFilePath;//日志文件的完整路径 string类型
	protected:
		LOG_LEVEL m_Loglevel;//日志记录级别，默认为LL_ERROR
		bool m_showLogFlag;//显示日志的标志，默认为true
		size_t m_maxLogFileSize;//日志文件大小 超过该大小将被删除，大小为10M
}

#endif
