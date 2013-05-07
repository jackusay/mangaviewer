#include "viewercommand.h"
#include "mangaviewer.h"
#include <QFileDialog>
#include <QString>
#include <QDebug>
#include "commandregistry.h"
ViewerCommand::ViewerCommand()
{
}
REGISTER_COMMAND(ViewerOpenFileCommand)
void ViewerOpenFileCommand::execute(MangaViewer *viewer)
{
        QString dir =QFileDialog::getExistingDirectory(0, tr("Open Directory"),
                                                       "",
                                                      QFileDialog::ShowDirsOnly
                                                      );
       if(dir=="")
        {
            return;
        }
        else
        {
           viewer->setPath(dir);
           viewer->go();
           viewer->getWidget()->update();
         }

}

REGISTER_COMMAND(ViewerEmptyCommand)
void ViewerEmptyCommand::execute(MangaViewer *viewer)
{
    //todo change the method to show a message on screen
    qDebug()<<"execute an empty command!";

}

REGISTER_COMMAND(ViewerGoCommand)
void ViewerGoCommand::execute(MangaViewer *viewer)
{
    viewer->go();
   viewer->getWidget()->update();
}

REGISTER_COMMAND(ViewerBackCommand)
void ViewerBackCommand::execute(MangaViewer *viewer)
{
    viewer->back();
    viewer->getWidget()->update();
}

REGISTER_COMMAND(ViewerNextPageCommand)
void ViewerNextPageCommand::execute(MangaViewer *viewer)
{
    FileManager *manager=viewer->getFileManager();
    manager->next();
    viewer->update();
    viewer->getWidget()->update();
}

REGISTER_COMMAND(ViewerPreviousPageCommand)
void ViewerPreviousPageCommand::execute(MangaViewer *viewer)
{

}

