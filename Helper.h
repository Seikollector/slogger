#ifndef HELPER_H
#define HELPER_H

#include <ctime>
#include <string>
#include <sstream>
#include <fstream>


namespace Helper
{
    template <class T>

    std::string ToString(const T &);
    struct DateTime
    {
        DateTime()
        {
            time_t ms;
            time(&ms);

            struct tm *info = localtime(&ms);

            D = info->tm_mday;
            M = info->tm_mon + 1;
            Y = 1900 + info-> tm_year;
            m = info->tm_min;
            H = info->tm_hour;
            S = info->tm_sec;
        }

        DateTime(int D, int M, int Y, int m, int H, int S) : D(D), M(M), Y(Y), m(m), H(H), S(S) {}
        DateTime(int D, int M, int Y) : D(D), M(M), Y(Y), m(0), H(0), S(0) {}

        DateTime Now() const
        {
            return DateTime();
        }
        int D, M, Y, m, H, S;

        std::string GetDateString() const
        {
            return std::string( D < 10 ? "0" : "") + ToString(D) +
                   std::string( M < 10 ? ".0" : ".") + ToString(M) + "." +
                   ToString(Y);
        }

        std::string GetTimeString(const std::string &sep = ":") const
        {
            return std::string( H < 10 ? "0" : "") + ToString(H) + sep +
                   std::string( m < 10 ? "0" : "") + ToString(m) + sep +
                   std::string( S < 10 ? "0" : "") + ToString(S);
        }
        std::string GetDateTimeString(const std::string &sep = ":") const
        {
            return GetDateString() + " " + GetTimeString(sep);
        }
    };

    template<class T>
    std::string ToString(const T &e)
    {
        std::ostringstream s;
        s << e;
        return s.str();
    }

    void WriteAppLog(const std::string &s)
    {
        std::ofstream file("AppLog.txt", std::ios::app);
        file << "[" << Helper::DateTime().GetDateTimeString() <<  "]" <<
        "\n" << s << std::endl << "\n";
    }
}


#endif // HELPER_H
