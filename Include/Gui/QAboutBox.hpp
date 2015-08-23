#ifndef QT_ABOUTBOX_HPP_INCLUDED
#define QT_ABOUTBOX_HPP_INCLUDED

#include <QDialog>
#include <Core/NModule.hpp>
#include <QModelIndex>
#include <QStandardItemModel>
#include <QLabel>
#include <QSpacerItem>
#include <QTableView>
#include <QComboBox>
#include <QGridLayout>
#include <QApplication>
#include <Gui/QPluginManagerDialog.hpp>
#include <Core/NObject.hpp>
#include <Gui/NeurotechnologyLogo.xpm>
#include <QStandardItemModel>
#include <Plugins/NPluginManager.hpp>
#include <memory>

namespace Neurotec { namespace Gui {


class QAboutBox : public QDialog
{
	Q_OBJECT
private:
	QVBoxLayout *verticalLayout_2;
	QHBoxLayout *horizontalLayout_2;
	QLabel *lblLogo;
	QVBoxLayout *verticalLayout;
	QLabel *lblTitle;
	QLabel *lblVersion;
	QLabel *lblCopyright;
	QSpacerItem *horizontalSpacer_2;
	QGridLayout *gridLayout;
	QLabel *lblModules;
	QLabel *lblActivated;
	QTableView *tvModules;
	QTableView *tvComponents;
	QHBoxLayout *horizontalLayout;
	QLabel *lblPluginManagers;
	QComboBox *cbPluginManagers;
	QPushButton *btnOpen;
	QSpacerItem *horizontalSpacer;
	QPushButton *btnOk;

	void setupUi()
	{
		if (objectName().isEmpty())
			setObjectName(QString::fromUtf8("QAboutBox"));
		resize(761, 439);
		verticalLayout_2 = new QVBoxLayout(this);
		verticalLayout_2->setSpacing(2);
		verticalLayout_2->setContentsMargins(3, 3, 3, 3);
		verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
		horizontalLayout_2 = new QHBoxLayout();
		horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
		lblLogo = new QLabel(this);
		lblLogo->setObjectName(QString::fromUtf8("lblLogo"));

		horizontalLayout_2->addWidget(lblLogo);

		verticalLayout = new QVBoxLayout();
		verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
		lblTitle = new QLabel(this);
		lblTitle->setObjectName(QString::fromUtf8("lblTitle"));

		verticalLayout->addWidget(lblTitle);

		lblVersion = new QLabel(this);
		lblVersion->setObjectName(QString::fromUtf8("lblVersion"));

		verticalLayout->addWidget(lblVersion);

		lblCopyright = new QLabel(this);
		lblCopyright->setObjectName(QString::fromUtf8("lblCopyright"));

		verticalLayout->addWidget(lblCopyright);


		horizontalLayout_2->addLayout(verticalLayout);

		horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

		horizontalLayout_2->addItem(horizontalSpacer_2);


		verticalLayout_2->addLayout(horizontalLayout_2);

		gridLayout = new QGridLayout();
		gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
		lblModules = new QLabel(this);
		lblModules->setObjectName(QString::fromUtf8("lblModules"));

		gridLayout->addWidget(lblModules, 0, 0, 1, 1);

		lblActivated = new QLabel(this);
		lblActivated->setObjectName(QString::fromUtf8("lblActivated"));

		gridLayout->addWidget(lblActivated, 0, 1, 1, 1);

		tvModules = new QTableView(this);
		tvModules->setObjectName(QString::fromUtf8("tvModules"));
		QFont font;
		font.setPointSize(8);
		tvModules->setFont(font);
		tvModules->setEditTriggers(QAbstractItemView::NoEditTriggers);
		tvModules->setSelectionMode(QAbstractItemView::SingleSelection);
		tvModules->setSelectionBehavior(QAbstractItemView::SelectRows);
		tvModules->setShowGrid(false);
		tvModules->setGridStyle(Qt::NoPen);
		tvModules->horizontalHeader()->setCascadingSectionResizes(true);
		tvModules->horizontalHeader()->setMinimumSectionSize(18);
		tvModules->horizontalHeader()->setStretchLastSection(true);
		tvModules->verticalHeader()->setStretchLastSection(false);

		gridLayout->addWidget(tvModules, 1, 0, 1, 1);

		tvComponents = new QTableView(this);
		tvComponents->setObjectName(QString::fromUtf8("tvComponents"));
		tvComponents->setEditTriggers(QAbstractItemView::NoEditTriggers);
		tvComponents->setSelectionBehavior(QAbstractItemView::SelectRows);
		tvComponents->setShowGrid(false);
		tvComponents->horizontalHeader()->setCascadingSectionResizes(true);
		tvComponents->horizontalHeader()->setMinimumSectionSize(18);
		tvComponents->horizontalHeader()->setStretchLastSection(true);
		tvComponents->verticalHeader()->setStretchLastSection(false);

		gridLayout->addWidget(tvComponents, 1, 1, 1, 1);

		gridLayout->setColumnStretch(0, 2);
		gridLayout->setColumnStretch(1, 1);

		verticalLayout_2->addLayout(gridLayout);

		horizontalLayout = new QHBoxLayout();
		horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
		lblPluginManagers = new QLabel(this);
		lblPluginManagers->setObjectName(QString::fromUtf8("lblPluginManagers"));

		horizontalLayout->addWidget(lblPluginManagers);

		cbPluginManagers = new QComboBox(this);
		cbPluginManagers->setObjectName(QString::fromUtf8("cbPluginManagers"));
		cbPluginManagers->setMinimumSize(QSize(150, 0));

		horizontalLayout->addWidget(cbPluginManagers);

		btnOpen = new QPushButton(this);
		btnOpen->setObjectName(QString::fromUtf8("btnOpen"));

		horizontalLayout->addWidget(btnOpen);

		horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

		horizontalLayout->addItem(horizontalSpacer);

		btnOk = new QPushButton(this);
		btnOk->setObjectName(QString::fromUtf8("btnOk"));

		horizontalLayout->addWidget(btnOk);


		verticalLayout_2->addLayout(horizontalLayout);


		retranslateUi();

		QMetaObject::connectSlotsByName(this);
	} // setupUi

	void retranslateUi()
	{
		setWindowTitle(QApplication::translate("QAboutBox", "Dialog", 0));
		lblLogo->setText(QApplication::translate("QAboutBox", "TextLabel", 0));
		lblTitle->setText(QApplication::translate("QAboutBox", "Title", 0));
		lblVersion->setText(QApplication::translate("QAboutBox", "Version", 0));
		lblCopyright->setText(QApplication::translate("QAboutBox", "Copyright", 0));
		lblModules->setText(QApplication::translate("QAboutBox", "Modules:", 0));
		lblActivated->setText(QApplication::translate("QAboutBox", "Activated:", 0));
		lblPluginManagers->setText(QApplication::translate("QAboutBox", "Plugin managers:", 0));
		btnOpen->setText(QApplication::translate("QAboutBox", "Open", 0));
		btnOk->setText(QApplication::translate("QAboutBox", "Ok", 0));
	} // retranslateUi
public:
	explicit QAboutBox(QString title, QString version, QString copyright, QWidget *parent = 0)
		: QDialog(parent)
	{
		setupUi();
		this->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
		lblCopyright->setText(copyright);
		lblTitle->setText(title);
		lblVersion->setText(version);
		lblLogo->setText("");
		lblLogo->setPixmap(QPixmap(NeurotechnologyLogo_XPM));
		this->setWindowTitle("About " + title);
		QStandardItemModel * model = new QStandardItemModel(this);
		model->setColumnCount(3);
		model->setHeaderData(0, Qt::Horizontal, "Title");
		model->setHeaderData(1, Qt::Horizontal, "Version");
		model->setHeaderData(2, Qt::Horizontal, "Copyright");
		tvModules->setModel(model);
		tvModules->verticalHeader()->hide();

		model = new QStandardItemModel(this);
		model->setColumnCount(2);
		model->setHeaderData(0, Qt::Horizontal, "Component");
		model->setHeaderData(1, Qt::Horizontal, "Value");
		tvComponents->setModel(model);
		tvComponents->verticalHeader()->hide();

		int managersCount;
		int moduleCount;
		::std::auto_ptr<Neurotec::Plugins::QNPluginManager*> pluginManagers(Neurotec::Plugins::QNPluginManager::GetInstances(&managersCount));
		::std::auto_ptr<Neurotec::QNModule*> loadedModules(Neurotec::QNModule::GetLoadedModules(&moduleCount));
		for(int i = 0; i < managersCount; i++)
		{
			cbPluginManagers->addItem(pluginManagers.get()[i]->GetInterfaceType(), QVariant::fromValue((void*)pluginManagers.get()[i]));
			for(int j = 0; j < pluginManagers.get()[i]->GetPlugins()->GetCount(); j++)
			{
				Neurotec::Plugins::QNPlugin * plugin = pluginManagers.get()[i]->GetPlugins()->Get(j);
				Neurotec::QNModule * module = plugin->GetModule();
				if(module)
				{
					for(int k = 0; k < moduleCount; k++)
					{
						if(module->Equals(loadedModules.get()[k]))
						{
							loadedModules.get()[k] = NULL;
							break;
						}
					}
				}
			}
		}

		for(int i = 0; i < moduleCount; i++)
		{
			if(loadedModules.get()[i] != NULL)
				moduleList.append(loadedModules.get()[i]);
		}

		RefreshComponents();
		tvModules->resizeColumnToContents(0);
	}

private slots:
	void on_tvModules_clicked(const QModelIndex &index)
	{
		if(index.isValid())
		{
			Neurotec::QNModule * module = moduleList[index.row()];
			ShowComponents(module);
			tvComponents->resizeRowsToContents();
		}
	}

	void on_btnOk_clicked()
	{
		accept();
	}

	void on_btnOpen_clicked()
	{
		Neurotec::Plugins::QNPluginManager * manager = (Neurotec::Plugins::QNPluginManager*)cbPluginManagers->itemData(cbPluginManagers->currentIndex()).value<void*>();
		if(!manager) return;
		Neurotec::Gui::QPluginManagerDialog dialog(manager, NULL, QString(), this);
		dialog.exec();
	}

private:
	QList<Neurotec::QNModule*> moduleList;
	void RefreshComponents()
	{
		QStandardItemModel * model = (QStandardItemModel*)tvModules->model();
		model->removeRows(0, model->rowCount());
		for(int i = 0; i < moduleList.count(); i++)
		{
			ShowModule(moduleList[i], model);
		}
		tvModules->resizeColumnsToContents();
	}

	void ShowModule(Neurotec::QNModule * module, QStandardItemModel * model)
	{
		QList<QStandardItem*> row;
		row << new QStandardItem(module->GetTitle())
			<< new QStandardItem(QString("%1.%2.%3.%4").arg(QString::number(module->GetVersionMajor()), QString::number(module->GetVersionMinor()), QString::number(module->GetVersionBuild()), QString::number(module->GetVersionRevision())))
			<< new QStandardItem(module->GetCopyright());
		model->appendRow(row);
	}

	void ShowComponents(Neurotec::QNModule * module)
	{
		QStandardItemModel * model = (QStandardItemModel*)tvComponents->model();
		model->removeRows(0, model->rowCount());
		QStringList split = ((QString)module->GetActivated()).split(QRegExp("[:,]"), QString::SkipEmptyParts);
		for(int i = 0; i < split.count() / 2; ++i)
		{
			model->appendRow(QList<QStandardItem*>()
				<< new QStandardItem(split.at(i*2).trimmed())
				<< new QStandardItem(split.at(i*2 + 1).trimmed()));
		}
		tvComponents->resizeColumnToContents(0);
	}
};

}}
#endif // QT_ABOUTBOX_HPP_INCLUDED
