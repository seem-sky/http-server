#ifndef FILE_READER_H
#define FILE_READER_H

#include "file.h"
#include "cache.h"

#include <boost/filesystem.hpp>
#include <string>

class file_reader
{
public:
    file_reader(const std::string& doc_root, const std::string& index_filename);
    file_ptr read(const std::string& src, bool do_reading = true);

private:
//    bool path_contains_file(boost::filesystem::path dir, boost::filesystem::path file);

private:
    std::string _doc_root;
    std::string _index_filename;
    cache _cache;
};

#endif // FILE_READER_H
