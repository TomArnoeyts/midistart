#include "saudio.h"
#include "ui_saudio.h"
#include <QString>
#include <QProcess>

SAudio::SAudio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SAudio)
{
    ui->setupUi(this);
}

SAudio::~SAudio()
{
    delete ui;
}

void SAudio::on_pushStopPA_clicked()
{
    QProcess process;
    process.start("pasuspender");
    process.close();
    ui->lblStatus->setText("STATUS: Pulse audio stopped...");
    ui->pushStopPA->setEnabled(false);
    ui->pushStartJack->setEnabled(true);
    ui->pushExitProgram->setEnabled(false);
}


void SAudio::on_pushStartJack_clicked()
{
    ui->pushStartJack->setEnabled(false);
    ui->pushstartFluidSynth->setEnabled(true);
    this->JACKProcess.start("jackd -d alsa --device hw:0 --rate 44100 --period 128 &> /tmp/jackd.out");
    this->JACKProcessID.start("pgrep jackd");
    QByteArray ba;
    if (this->JACKProcessID.waitForStarted(-1)) {
        while(this->JACKProcessID.waitForReadyRead(-1)) {
            ba += this->JACKProcessID.readAllStandardOutput();
        }
    }
    this->JACKProcessID.close();

    ui->lblStatus->setText("STATUS: JACK server started. ProcessID: " + QString(ba.data()));
    ui->lblPortJack->setText(QString(ba.data()));
}

void SAudio::on_pushstartFluidSynth_clicked()
{
    this->FLUISYNTHProcess.start("fluidsynth --server --no-shell --audio-driver=jack --connect-jack-outputs --reverb=0 --chorus=0 --gain=0.8 /usr/share/sounds/sf2/FluidR3_GM.sf2 &> /tmp/fluidsynth.out & sleep 1");
    this->FLUISYNTHProcessID.start("pgrep fluidsynth");
    QByteArray ba;
    if (this->FLUISYNTHProcess.waitForStarted(-1)) {
        while(this->FLUISYNTHProcessID.waitForReadyRead(-1)) {
            ba += this->FLUISYNTHProcessID.readAllStandardOutput();
        }
    }
    this->FLUISYNTHProcessID.close();

    ui->lblStatus->setText("STATUS: Fluid Synth server started. ProcessID: " + QString(ba.data()));
    ui->lblPortFluidSynth->setText(QString(ba.data()));
    ui->pushstartFluidSynth->setEnabled(false);
    ui->pushStartRosegarden->setEnabled(true);
    ui->pushStartLinthesia->setEnabled(true);
    ui->pushPatchage->setEnabled(true);
    ui->pushStopFluidSynth->setEnabled(true);
    ui->pushVMPK->setEnabled(true);
}

void SAudio::on_pushStopFluidSynth_clicked()
{
    this->FLUISYNTHProcess.close();
    ui->lblPortFluidSynth->setText("0");
    ui->pushStartRosegarden->setEnabled(false);
    ui->pushStartLinthesia->setEnabled(false);
    ui->pushStopFluidSynth->setEnabled(false);
    ui->pushVMPK->setEnabled(false);
    ui->pushPatchage->setEnabled(false);
    ui->pushStopJACK->setEnabled(true);
    ui->lblStatus->setText("STATUS: FluidSynth server stopped...");
}
void SAudio::on_pushExitProgram_clicked()
{
    exit(0);
}

void SAudio::on_pushStopJACK_clicked()
{
    ui->lblPortJack->setText("0");
    this->JACKProcess.close();
    ui->pushStopPA->setEnabled(true);
    ui->pushExitProgram->setEnabled(true);
    ui->pushStopJACK->setEnabled(false);
    ui->lblStatus->setText("STATUS: JACK server stopped...");
}

void SAudio::on_pushPatchage_clicked()
{
    QProcess process;
    process.startDetached("patchage");
    ui->lblStatus->setText("STATUS: Patchage started...");
}

void SAudio::on_pushVMPK_clicked()
{
    QProcess process;
    process.startDetached("vmpk");
    ui->lblStatus->setText("STATUS: VMPK started...");
}

void SAudio::on_pushStartLinthesia_clicked()
{
    QProcess process;
    process.startDetached("linthesia");
    ui->lblStatus->setText("STATUS: linthesia started...");
}

void SAudio::on_pushSSR_clicked()
{
    QProcess process;
    process.startDetached("simplescreenrecorder");
    ui->lblStatus->setText("STATUS: Simple Screen Recorder started...");
}

void SAudio::on_pushSSR_2_clicked()
{
    QProcess process;
    process.startDetached("openshot");
    ui->lblStatus->setText("STATUS: Openshot Video Editor started...");
}

void SAudio::on_pushStartRosegarden_clicked()
{
    QProcess process;
    process.startDetached("rosegarden");
    ui->lblStatus->setText("STATUS: Rosegarden sequencer started...");
}
