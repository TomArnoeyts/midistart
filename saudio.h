#ifndef SAUDIO_H
#define SAUDIO_H

#include <QWidget>
#include <QProcess>

namespace Ui {
class SAudio;
}

class SAudio : public QWidget
{
    Q_OBJECT

public:
    explicit SAudio(QWidget *parent = 0);
    ~SAudio();

private slots:
    void on_pushStopPA_clicked();

    void on_pushStartJack_clicked();

    void on_pushstartFluidSynth_clicked();

    void on_pushStopFluidSynth_clicked();

    void on_pushExitProgram_clicked();

    void on_pushStopJACK_clicked();

    void on_pushPatchage_clicked();

    void on_pushVMPK_clicked();

    void on_pushStartLinthesia_clicked();

    void on_pushSSR_clicked();

    void on_pushSSR_2_clicked();

    void on_pushStartRosegarden_clicked();

private:
    Ui::SAudio *ui;
    QProcess JACKProcess;
    QProcess JACKProcessID;
    QProcess FLUISYNTHProcess;
    QProcess FLUISYNTHProcessID;
};

#endif // SAUDIO_H
