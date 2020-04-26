#include "fileio.h"

FileIO::FileIO(QObject *parent)
    : QObject(parent)
{
}

QString FileIO::getHomeAddress()
{
    return QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
}

FileIO::~FileIO()
{
}

bool FileIO::read()
{
    if(m_source.isEmpty()) {
        return false;
    }
    QFile file(m_source.toLocalFile());
    if(!file.exists()) {
        qWarning() << "Does not exits: " << m_source.toLocalFile();
        return false;
    }
    if(file.open(QIODevice::ReadOnly)) {
        QTextStream stream(&file);
        m_text = stream.readAll();
        emit textChanged(m_text);
        return true;
    }
}

void FileIO::write()
{
    if(m_source.isEmpty()) {
        qDebug() << "is empty";
        return;
    }
    const QString& homePath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    qDebug() << homePath+"/"+m_source.toString();
    QFile file(homePath+"/"+m_source.toString());
    if(file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream << m_text;
    }
}

QUrl FileIO::source() const
{
    return m_source;
}

QString FileIO::text() const
{
    return m_text;
}

void FileIO::setSource(QUrl source)
{
    if (m_source == source)
        return;

    m_source = source;
    emit sourceChanged(source);
}

void FileIO::setText(QString text)
{
    if (m_text == text)
        return;

    m_text = text;
    emit textChanged(text);
}

QString FileIO::getExistProjectList(QString path)
{
    QString projects_name_list="";
    QString ab_path=QStandardPaths::writableLocation(QStandardPaths::HomeLocation)+"/"+path;
    QDir dir(ab_path);
    dir.setFilter(QDir::AllDirs);

    QFileInfoList list = dir.entryInfoList();
    for (int i = 0; i < list.size(); ++i)
    {
        QStringList temp=list.at(i).filePath().split("/");
        QString folderName=temp.at(temp.length()-1);
        if(folderName!="." && folderName!="..")
        {
            projects_name_list+=folderName+"#";
        }
    }
    projects_name_list.remove(projects_name_list.length()-1,1);
//    qDebug() << projects_name_list;
    return projects_name_list;
}

QString FileIO::getExistFileList(QString path)
{
    QString files_name_list="";
    QString ab_path=QStandardPaths::writableLocation(QStandardPaths::HomeLocation)+"/"+path;
    QDir dir(ab_path);
    dir.setFilter(QDir::Files);

    QFileInfoList list = dir.entryInfoList();
    for (int i = 0; i < list.size(); ++i)
    {
        QStringList temp=list.at(i).filePath().split("/");
        QString fileName=temp.at(temp.length()-1);
        files_name_list+=fileName+"#";
    }
    files_name_list.remove(files_name_list.length()-1,1);
    qDebug() << files_name_list;
    return files_name_list;
}

void FileIO::setCurrentProject(QString path)
{
    controller = Controller::getInstance();

    controller->_current_project_name=path;
    qDebug() << controller->_current_project_name;
}

QString FileIO::getCurrentProject()
{
    qDebug() << controller->_current_project_name;
    return controller->_current_project_name;
}
