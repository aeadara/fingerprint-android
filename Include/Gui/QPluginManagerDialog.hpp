#ifndef QT_PLUGINMANAGERDIALOG_HPP_INCLUDED
#define QT_PLUGINMANAGERDIALOG_HPP_INCLUDED

#include <QDialog>
#include <Plugins/NPluginManager.hpp>
#include <Plugins/NPlugin.hpp>
#include <Core/NObject.hpp>
#include <QTime>
#include <QModelIndex>
#include <QThread>
#include <QLabel>
#include <QLineEdit>
#include <QSpacerItem>
#include <QTableView>
#include <QGridLayout>
#include <QTextEdit>
#include <QFileDialog>
#include <QPushButton>
#include <QHeaderView>
#include <QApplication>
#include <QStandardItemModel>

Q_DECLARE_METATYPE(Neurotec::Plugins::QNPlugin*)

namespace Neurotec { namespace Gui {

class QPluginManagerDialog;

class AsyncRun : public QThread
{
	Q_OBJECT
private:
	enum Target
	{
		AddPlugin,
		PluginManagerFunc,
		PluginFunc
	};

	Target _target;
	Neurotec::Plugins::QNPluginManager * _pluginManager;
	Neurotec::Plugins::QNPlugin * _plugin;
	void (Neurotec::Plugins::QNPluginManager::*_pluginManagerFunction)();
	void (Neurotec::Plugins::QNPlugin::*_pluginFunction)();
	QString _param;

	AsyncRun(void (Neurotec::Plugins::QNPluginManager::*ptr)(), Neurotec::Plugins::QNPluginManager * instance, QObject * parent = NULL ) :
		QThread(parent)
	{
		_pluginManagerFunction = ptr;
		_pluginManager = instance;
		_target = PluginManagerFunc;
	}
	AsyncRun(void (Neurotec::Plugins::QNPlugin::*ptr)(), Neurotec::Plugins::QNPlugin * plugin, QObject * parent = NULL) : QThread(parent)
	{
		_pluginFunction = ptr;
		_plugin = plugin;
		_target = PluginFunc;
	}
	AsyncRun(Neurotec::Plugins::QNPluginManager* manager, QString param, QObject * parent = NULL) :
		QThread(parent)
	{
		_pluginManager = manager;
		_param = param;
		_target = AddPlugin;
	}
public:
	~AsyncRun()
	{
		if(isRunning())
			terminate();
	}
protected:
	void run()
	{
		if(_target == AddPlugin)
		{
			_pluginManager->GetPlugins()->Add(_param);
		}
		if(_target == PluginManagerFunc)
		{
			(_pluginManager->*_pluginManagerFunction)();
		}
		if(_target == PluginFunc)
		{
			(_plugin->*_pluginFunction)();
		}
	}

	static void AddPluginAsync(Neurotec::Plugins::QNPluginManager * pManager, QString plugin, QObject * parent)
	{
		AsyncRun * target = new AsyncRun(pManager, plugin, parent);
		target->start();
	}
	static void PlugAllAsync(Neurotec::Plugins::QNPluginManager * pManager, QObject * parent)
	{
		AsyncRun * target = new AsyncRun(&Neurotec::Plugins::QNPluginManager::PlugAll, pManager, parent);
		target->run();
	}
	static void UnplugAllAsync(Neurotec::Plugins::QNPluginManager * pManager, QObject * parent)
	{
		AsyncRun * target = new AsyncRun(&Neurotec::Plugins::QNPluginManager::UnplugAll, pManager, parent);
		target->run();
	}
	static void RefreshAsync(Neurotec::Plugins::QNPluginManager * pManager, QObject * parent)
	{
		AsyncRun * target = new AsyncRun(&Neurotec::Plugins::QNPluginManager::Refresh, pManager, parent);
		target->run();
	}
	static void PlugAsync(Neurotec::Plugins::QNPlugin * plugin, QObject * parent)
	{
		AsyncRun * target = new AsyncRun(&Neurotec::Plugins::QNPlugin::Plug, plugin, parent);
		target->start();
	}
	static void UnplugAsync(Neurotec::Plugins::QNPlugin * plugin, QObject * parent)
	{
		AsyncRun * target = new AsyncRun(&Neurotec::Plugins::QNPlugin::Unplug, plugin, parent);
		target->start();
	}
	static void EbableAsync(Neurotec::Plugins::QNPlugin * plugin, QObject * parent)
	{
		AsyncRun * target = new AsyncRun(&Neurotec::Plugins::QNPlugin::Enable, plugin, parent);
		target->start();
	}
	static void DisableAsync(Neurotec::Plugins::QNPlugin * plugin, QObject * parent)
	{
		AsyncRun * target = new AsyncRun(&Neurotec::Plugins::QNPlugin::Disable, plugin, parent);
		target->start();
	}

	friend class QPluginManagerDialog;
};

class QPluginManagerDialog : public QDialog
{
	Q_OBJECT
private:
	QVBoxLayout *verticalLayout_3;
	QGridLayout *topLayout;
	QLabel *lblInterfaceType;
	QLabel *lblInterfaceTypeValue;
	QLabel *lblInterfaceVersion;
	QLabel *lblInterfaceVersionValue;
	QLabel *lblSearchPath;
	QLineEdit *lePath;
	QPushButton *btnBrowse;
	QPushButton *btnUnplugAll;
	QHBoxLayout *horizontalLayout;
	QSpacerItem *horizontalSpacer;
	QPushButton *btnAdd;
	QPushButton *btnRefresh;
	QPushButton *btnPlugAll;
	QLabel *lblPlugins;
	QTableView *tvPlugins;
	QGridLayout *bottomLayout;
	QVBoxLayout *layoutButtons;
	QPushButton *btnEnable;
	QPushButton *btnDisable;
	QPushButton *btnPlug;
	QPushButton *btnUnplug;
	QSpacerItem *verticalSpacer;
	QPushButton *btnOk;
	QTabWidget *tabWidget;
	QWidget *tabError;
	QVBoxLayout *verticalLayout;
	QTextEdit *teError;
	QWidget *tabActivated;
	QVBoxLayout *verticalLayout_2;
	QTableView *tvActivated;
	QLabel *lblTotalInfo;

	void setupUi()
	{
		if (objectName().isEmpty())
			setObjectName(QString::fromUtf8("QPluginManagerDialog"));
		resize(752, 551);
		verticalLayout_3 = new QVBoxLayout(this);
		verticalLayout_3->setSpacing(2);
		verticalLayout_3->setContentsMargins(3, 3, 3, 3);
		verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
		topLayout = new QGridLayout();
		topLayout->setSpacing(3);
		topLayout->setObjectName(QString::fromUtf8("topLayout"));
		lblInterfaceType = new QLabel(this);
		lblInterfaceType->setObjectName(QString::fromUtf8("lblInterfaceType"));
		QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
		sizePolicy.setHorizontalStretch(0);
		sizePolicy.setVerticalStretch(0);
		sizePolicy.setHeightForWidth(lblInterfaceType->sizePolicy().hasHeightForWidth());
		lblInterfaceType->setSizePolicy(sizePolicy);

		topLayout->addWidget(lblInterfaceType, 0, 0, 1, 1);

		lblInterfaceTypeValue = new QLabel(this);
		lblInterfaceTypeValue->setObjectName(QString::fromUtf8("lblInterfaceTypeValue"));

		topLayout->addWidget(lblInterfaceTypeValue, 0, 2, 1, 1);

		lblInterfaceVersion = new QLabel(this);
		lblInterfaceVersion->setObjectName(QString::fromUtf8("lblInterfaceVersion"));
		sizePolicy.setHeightForWidth(lblInterfaceVersion->sizePolicy().hasHeightForWidth());
		lblInterfaceVersion->setSizePolicy(sizePolicy);

		topLayout->addWidget(lblInterfaceVersion, 1, 0, 1, 1);

		lblInterfaceVersionValue = new QLabel(this);
		lblInterfaceVersionValue->setObjectName(QString::fromUtf8("lblInterfaceVersionValue"));

		topLayout->addWidget(lblInterfaceVersionValue, 1, 2, 1, 1);

		lblSearchPath = new QLabel(this);
		lblSearchPath->setObjectName(QString::fromUtf8("lblSearchPath"));
		sizePolicy.setHeightForWidth(lblSearchPath->sizePolicy().hasHeightForWidth());
		lblSearchPath->setSizePolicy(sizePolicy);

		topLayout->addWidget(lblSearchPath, 2, 0, 1, 1);

		lePath = new QLineEdit(this);
		lePath->setObjectName(QString::fromUtf8("lePath"));
		lePath->setFrame(true);
		lePath->setEchoMode(QLineEdit::Normal);
		lePath->setReadOnly(true);

		topLayout->addWidget(lePath, 2, 2, 1, 1);

		btnBrowse = new QPushButton(this);
		btnBrowse->setObjectName(QString::fromUtf8("btnBrowse"));
		sizePolicy.setHeightForWidth(btnBrowse->sizePolicy().hasHeightForWidth());
		btnBrowse->setSizePolicy(sizePolicy);

		topLayout->addWidget(btnBrowse, 2, 3, 1, 1);

		btnUnplugAll = new QPushButton(this);
		btnUnplugAll->setObjectName(QString::fromUtf8("btnUnplugAll"));
		sizePolicy.setHeightForWidth(btnUnplugAll->sizePolicy().hasHeightForWidth());
		btnUnplugAll->setSizePolicy(sizePolicy);

		topLayout->addWidget(btnUnplugAll, 3, 3, 1, 1);

		horizontalLayout = new QHBoxLayout();
		horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
		horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

		horizontalLayout->addItem(horizontalSpacer);

		btnAdd = new QPushButton(this);
		btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
		sizePolicy.setHeightForWidth(btnAdd->sizePolicy().hasHeightForWidth());
		btnAdd->setSizePolicy(sizePolicy);

		horizontalLayout->addWidget(btnAdd);

		btnRefresh = new QPushButton(this);
		btnRefresh->setObjectName(QString::fromUtf8("btnRefresh"));
		sizePolicy.setHeightForWidth(btnRefresh->sizePolicy().hasHeightForWidth());
		btnRefresh->setSizePolicy(sizePolicy);

		horizontalLayout->addWidget(btnRefresh);

		btnPlugAll = new QPushButton(this);
		btnPlugAll->setObjectName(QString::fromUtf8("btnPlugAll"));
		sizePolicy.setHeightForWidth(btnPlugAll->sizePolicy().hasHeightForWidth());
		btnPlugAll->setSizePolicy(sizePolicy);

		horizontalLayout->addWidget(btnPlugAll);

		topLayout->addLayout(horizontalLayout, 3, 2, 1, 1);

		lblPlugins = new QLabel(this);
		lblPlugins->setObjectName(QString::fromUtf8("lblPlugins"));
		sizePolicy.setHeightForWidth(lblPlugins->sizePolicy().hasHeightForWidth());
		lblPlugins->setSizePolicy(sizePolicy);

		topLayout->addWidget(lblPlugins, 3, 0, 1, 1);

		tvPlugins = new QTableView(this);
		tvPlugins->setObjectName(QString::fromUtf8("tvPlugins"));
		QFont font;
		font.setPointSize(8);
		tvPlugins->setFont(font);
		tvPlugins->setEditTriggers(QAbstractItemView::NoEditTriggers);
		tvPlugins->setSelectionBehavior(QAbstractItemView::SelectRows);
		tvPlugins->setShowGrid(false);
		tvPlugins->setWordWrap(false);
		tvPlugins->horizontalHeader()->setCascadingSectionResizes(true);
		tvPlugins->horizontalHeader()->setMinimumSectionSize(27);
		tvPlugins->horizontalHeader()->setStretchLastSection(true);
		tvPlugins->verticalHeader()->setVisible(false);

		topLayout->addWidget(tvPlugins, 4, 0, 1, 4);


		verticalLayout_3->addLayout(topLayout);

		bottomLayout = new QGridLayout();
		bottomLayout->setSpacing(3);
		bottomLayout->setObjectName(QString::fromUtf8("bottomLayout"));
		layoutButtons = new QVBoxLayout();
		layoutButtons->setObjectName(QString::fromUtf8("layoutButtons"));
		btnEnable = new QPushButton(this);
		btnEnable->setObjectName(QString::fromUtf8("btnEnable"));
		sizePolicy.setHeightForWidth(btnEnable->sizePolicy().hasHeightForWidth());
		btnEnable->setSizePolicy(sizePolicy);

		layoutButtons->addWidget(btnEnable);

		btnDisable = new QPushButton(this);
		btnDisable->setObjectName(QString::fromUtf8("btnDisable"));
		sizePolicy.setHeightForWidth(btnDisable->sizePolicy().hasHeightForWidth());
		btnDisable->setSizePolicy(sizePolicy);

		layoutButtons->addWidget(btnDisable);

		btnPlug = new QPushButton(this);
		btnPlug->setObjectName(QString::fromUtf8("btnPlug"));
		sizePolicy.setHeightForWidth(btnPlug->sizePolicy().hasHeightForWidth());
		btnPlug->setSizePolicy(sizePolicy);

		layoutButtons->addWidget(btnPlug);

		btnUnplug = new QPushButton(this);
		btnUnplug->setObjectName(QString::fromUtf8("btnUnplug"));
		sizePolicy.setHeightForWidth(btnUnplug->sizePolicy().hasHeightForWidth());
		btnUnplug->setSizePolicy(sizePolicy);

		layoutButtons->addWidget(btnUnplug);

		verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

		layoutButtons->addItem(verticalSpacer);

		btnOk = new QPushButton(this);
		btnOk->setObjectName(QString::fromUtf8("btnOk"));
		sizePolicy.setHeightForWidth(btnOk->sizePolicy().hasHeightForWidth());
		btnOk->setSizePolicy(sizePolicy);

		layoutButtons->addWidget(btnOk);


		bottomLayout->addLayout(layoutButtons, 0, 1, 2, 1);

		tabWidget = new QTabWidget(this);
		tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
		QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
		sizePolicy1.setHorizontalStretch(0);
		sizePolicy1.setVerticalStretch(0);
		sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
		tabWidget->setSizePolicy(sizePolicy1);
		tabWidget->setMaximumSize(QSize(2048, 170));
		tabError = new QWidget();
		tabError->setObjectName(QString::fromUtf8("tabError"));
		verticalLayout = new QVBoxLayout(tabError);
		verticalLayout->setSpacing(0);
		verticalLayout->setContentsMargins(0, 0, 0, 0);
		verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
		teError = new QTextEdit(tabError);
		teError->setObjectName(QString::fromUtf8("teError"));
		teError->setEnabled(false);

		verticalLayout->addWidget(teError);

		tabWidget->addTab(tabError, QString());
		tabActivated = new QWidget();
		tabActivated->setObjectName(QString::fromUtf8("tabActivated"));
		verticalLayout_2 = new QVBoxLayout(tabActivated);
		verticalLayout_2->setSpacing(0);
		verticalLayout_2->setContentsMargins(0, 0, 0, 0);
		verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
		tvActivated = new QTableView(tabActivated);
		tvActivated->setObjectName(QString::fromUtf8("tvActivated"));
		tvActivated->setFont(font);
		tvActivated->setEditTriggers(QAbstractItemView::NoEditTriggers);
		tvActivated->setSelectionMode(QAbstractItemView::SingleSelection);
		tvActivated->setSelectionBehavior(QAbstractItemView::SelectRows);
		tvActivated->horizontalHeader()->setMinimumSectionSize(18);
		tvActivated->horizontalHeader()->setStretchLastSection(true);
		tvActivated->verticalHeader()->setVisible(false);

		verticalLayout_2->addWidget(tvActivated);

		tabWidget->addTab(tabActivated, QString());

		bottomLayout->addWidget(tabWidget, 0, 0, 1, 1);

		lblTotalInfo = new QLabel(this);
		lblTotalInfo->setObjectName(QString::fromUtf8("lblTotalInfo"));

		bottomLayout->addWidget(lblTotalInfo, 1, 0, 1, 1);


		verticalLayout_3->addLayout(bottomLayout);

		verticalLayout_3->setStretch(0, 1);

		retranslateUi();

		tabWidget->setCurrentIndex(1);

		QMetaObject::connectSlotsByName(this);
	} // setupUi

	void retranslateUi()
	{
		setWindowTitle(QApplication::translate("QPluginManagerDialog", "Plugin Manager", 0));
		lblInterfaceType->setText(QApplication::translate("QPluginManagerDialog", "InterfaceType:", 0));
		lblInterfaceTypeValue->setText(QApplication::translate("QPluginManagerDialog", "Type", 0));
		lblInterfaceVersion->setText(QApplication::translate("QPluginManagerDialog", "Interface versions:", 0));
		lblInterfaceVersionValue->setText(QApplication::translate("QPluginManagerDialog", "Version", 0));
		lblSearchPath->setText(QApplication::translate("QPluginManagerDialog", "Plugin search path:", 0));
		btnBrowse->setText(QApplication::translate("QPluginManagerDialog", "...", 0));
		btnUnplugAll->setText(QApplication::translate("QPluginManagerDialog", "Unplug all", 0));
		btnAdd->setText(QApplication::translate("QPluginManagerDialog", "Add ...", 0));
		btnRefresh->setText(QApplication::translate("QPluginManagerDialog", "Refresh", 0));
		btnPlugAll->setText(QApplication::translate("QPluginManagerDialog", "Plug all", 0));
		lblPlugins->setText(QApplication::translate("QPluginManagerDialog", "Plugins:", 0));
		btnEnable->setText(QApplication::translate("QPluginManagerDialog", "Enable", 0));
		btnDisable->setText(QApplication::translate("QPluginManagerDialog", "Disable", 0));
		btnPlug->setText(QApplication::translate("QPluginManagerDialog", "Plug", 0));
		btnUnplug->setText(QApplication::translate("QPluginManagerDialog", "Unplug", 0));
		btnOk->setText(QApplication::translate("QPluginManagerDialog", "Ok", 0));
		tabWidget->setTabText(tabWidget->indexOf(tabError), QApplication::translate("QPluginManagerDialog", "Error", 0));
		tabWidget->setTabText(tabWidget->indexOf(tabActivated), QApplication::translate("QPluginManagerDialog", "Activated", 0));
		lblTotalInfo->setText(QApplication::translate("QPluginManagerDialog", "Total info", 0));
	} // retranslateUi

public:
	explicit QPluginManagerDialog(Neurotec::Plugins::QNPluginManager * pManager, Neurotec::Plugins::QNPlugin * selectedPlugin = NULL, QString title = QString(), QWidget *parent = 0)
		: QDialog(parent)
	{
		setupUi();
		setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
		if(!title.isNull() && !title.isEmpty())
			setWindowTitle(title);

		QObject::connect(btnAdd, SIGNAL(clicked()), this, SLOT(OnBtnAddClick()));
		QObject::connect(btnBrowse, SIGNAL(clicked()), this, SLOT(OnBtnBrowseClick()));
		QObject::connect(btnDisable, SIGNAL(clicked()), this, SLOT(OnBtnDisableClick()));
		QObject::connect(btnEnable, SIGNAL(clicked()), this, SLOT(OnBtnEnableClick()));
		QObject::connect(btnOk, SIGNAL(clicked()), this, SLOT(close()));
		QObject::connect(btnPlug, SIGNAL(clicked()), this, SLOT(OnBtnPlugClick()));
		QObject::connect(btnPlugAll, SIGNAL(clicked()), this, SLOT(OnBtnPlugAllClick()));
		QObject::connect(btnRefresh, SIGNAL(clicked()), this, SLOT(OnBtnRefreshClick()));
		QObject::connect(btnUnplug, SIGNAL(clicked()), this, SLOT(OnBtnUnplugClick()));
		QObject::connect(btnUnplugAll, SIGNAL(clicked()), this, SLOT(OnBtnUnplugAllClick()));
		QObject::connect(tvPlugins, SIGNAL(clicked(QModelIndex)), this, SLOT(OnPluginClick(QModelIndex)));

		QStandardItemModel * model = new QStandardItemModel(this);
		model->setColumnCount(13);
		model->setHeaderData(0, Qt::Horizontal, "Title");
		model->setHeaderData(1, Qt::Horizontal, "Version");
		model->setHeaderData(2, Qt::Horizontal, "Copyright");
		model->setHeaderData(3, Qt::Horizontal, "State");
		model->setHeaderData(4, Qt::Horizontal, "Load time");
		model->setHeaderData(5, Qt::Horizontal, "Plug time");
		model->setHeaderData(6, Qt::Horizontal, "Selected interface version");
		model->setHeaderData(7, Qt::Horizontal, "Name");
		model->setHeaderData(8, Qt::Horizontal, "File name");
		model->setHeaderData(9, Qt::Horizontal, "Interface type");
		model->setHeaderData(10, Qt::Horizontal, "Interface versions");
		model->setHeaderData(11, Qt::Horizontal, "Priority");
		model->setHeaderData(12, Qt::Horizontal, "Incompatible plugins");
		tvPlugins->setModel(model);

		model = new QStandardItemModel(this);
		model->setColumnCount(2);
		model->setHeaderData(0, Qt::Horizontal, "Component");
		model->setHeaderData(1, Qt::Horizontal, "Value");
		tvActivated->setModel(model);

		pluginManager = pManager;
		OnPluginManagerChanged();
		tvPlugins->setFocus();

		OnSetSelectedPlugin(selectedPlugin);
		qRegisterMetaType<Neurotec::Plugins::QNPlugin*>();
	}

protected:
	void closeEvent(QCloseEvent *)
	{
		if(pluginManager)
		{
			QStandardItemModel * model = (QStandardItemModel*)tvPlugins->model();
			for(int i = 0; i < model->rowCount(); i++)
			{
				Neurotec::Plugins::QNPlugin * plugin = (Neurotec::Plugins::QNPlugin*)model->item(i, 0)->data().value<void*>();
				plugin->RemovePropertyChangedCallback(PuginChanged, this);
			}
			pluginManager->GetPlugins()->RemoveCollectionChangedCallback(PluginManager_PluginAdded, this);
			pluginManager->GetDisabledPlugins()->RemoveCollectionChangedCallback(PluginManager_DisabledPluginCanged, this);
		}
	}

private:
	static const int StateCollumn = 3;
	static const int LoadTimeCollumn = 4;
	static const int PlugTimeCollumn = 5;

	Neurotec::Plugins::QNPluginManager * pluginManager;
	QString GetInterfaceVersionsString()
	{
		if(!pluginManager) return QString();
		int count;
		Neurotec::QNVersionRange * versions = pluginManager->GetInterfaceVersions(&count);
		QString value = InterfaceVersionsToString(versions, count);
		delete [] versions;
		return value;
	}

	QString GetInterfaceVersionsString(Neurotec::Plugins::QNPluginModule * module)
	{
		if(!module) return QString();
		int count;
		Neurotec::QNVersionRange * versions = module->GetInterfaceVersions(&count);
		QString resul = InterfaceVersionsToString(versions, count);
		delete [] versions;
		return resul;
	}

	QString InterfaceVersionsToString(Neurotec::QNVersionRange * pVersions, int count)
	{
		QString value;
		for(int i = 0; i < count; i++)
		{
			if(value.count() != 0)
				value.append(", ");
			value.append(pVersions[i].ToString());
		}
		return value;
	}

	Neurotec::Plugins::QNPlugin * SelectedPlugin()
	{
		QModelIndexList selected = tvPlugins->selectionModel()->selection().indexes();
		if(selected.count() != -1)
			return NULL;

		return (Neurotec::Plugins::QNPlugin*)selected.at(0).data().value<void*>();
	}

	void AddPlugin(Neurotec::Plugins::QNPlugin * plugin)
	{
		Neurotec::Plugins::QNPluginModule * module = plugin->GetModule();
		QList<QStandardItem*> item;
		item << new QStandardItem(module == NULL? QString() : QString("%1 (%2)").arg(module->GetTitle(), NModuleOptionsToString(module->GetOptions())))
			 << new QStandardItem(GetModuleVersion(module))
			 << new QStandardItem(module == NULL? QString() : module->GetCopyright())
			 << new QStandardItem(QString())
			 << new QStandardItem(QString())
			 << new QStandardItem(QString())
			 << new QStandardItem(plugin->GetSelectedInterfaceVersion().ToString())
			 << new QStandardItem(module == NULL? QString() : module->GetPluginName())
			 << new QStandardItem(plugin->GetFileName())
			 << new QStandardItem(module == NULL? QString() : module->GetInterfaceType())
			 << new QStandardItem(GetInterfaceVersionsString(module))
			 << new QStandardItem(module == NULL? QString() : QString::number(module->GetPriority()))
			 << new QStandardItem(module == NULL? QString() : module->GetIncompatiblePlugins());
		item[0]->setData(QVariant::fromValue((void*)plugin));
		QStandardItemModel * model = (QStandardItemModel*)tvPlugins->model();
		model->appendRow(item);

		try
		{
			plugin->AddPropertyChangedCallback(PuginChanged, this);
			UpdatePluginState(model->rowCount() - 1);
			tvPlugins->resizeColumnToContents(0);
			tvPlugins->resizeColumnToContents(1);
		}
		catch(...){}
	}

	void UpdatePluginState(int row)
	{
		QStandardItemModel * model = (QStandardItemModel*)tvPlugins->model();
		Neurotec::Plugins::QNPlugin * plugin = (Neurotec::Plugins::QNPlugin*)model->item(row, 0)->data().value<void*>();
		QStandardItem * item = model->item(row, StateCollumn);
		item->setText(NPluginStateToString(plugin->GetState()));
		Neurotec::QNException * error = plugin->GetError();
		item->setToolTip(error == NULL? QString() : error->ToString());
		if(error) delete error;

		item = model->item(row, LoadTimeCollumn);
		if(plugin->GetLoadTime().IsValid())
			item->setText(QString::number(QTimeTotalSeconds(plugin->GetLoadTime()), 'g', 2) + " s");
		else item->setText(QString());

		item = model->item(row, PlugTimeCollumn);
		if(plugin->GetPlugTime().IsValid())
			item->setText(QString::number(QTimeTotalSeconds(plugin->GetPlugTime()), 'g', 2) + " s");
		else item->setText(QString());
	}

	void UpdatePlugin(Neurotec::Plugins::QNPlugin * plugin)
	{
		QStandardItemModel * model = (QStandardItemModel*)tvPlugins->model();
		for(int i = 0; i < model->rowCount(); i++)
		{
			Neurotec::Plugins::QNPlugin * item = (Neurotec::Plugins::QNPlugin*)model->item(i)->data().value<void*>();
			if(item->Equals(plugin))
			{
				UpdatePluginState(i);
				if(tvPlugins->selectionModel()->selectedRows().contains(model->item(i)->index())) OnSelectedPluginChanged();
			}
		}
	}

	static void PluginManager_DisabledPluginCanged(Neurotec::QNObjectBase * pObject, Neurotec::Collections::NCollectionChangedAction action,
												   int newIndex, const QNString * arNewItems, int newItemsCount,
												   int oldIndex, const QNString * arOldItems, int oldItemsCount, void * pParam)
	{
		QPluginManagerDialog * dialog = (QPluginManagerDialog*)pParam;
		QMetaObject::invokeMethod(dialog, "UpdateTotalInfo", Qt::QueuedConnection);
		Q_UNUSED(pObject);
		Q_UNUSED(action);
		Q_UNUSED(newIndex);
		Q_UNUSED(arNewItems);
		Q_UNUSED(newItemsCount);
		Q_UNUSED(oldIndex);
		Q_UNUSED(arOldItems);
		Q_UNUSED(oldItemsCount);
	}

	static void PluginManager_PluginAdded(Neurotec::QNObjectBase * pObject, Neurotec::Collections::NCollectionChangedAction action,
										  int newIndex, Neurotec::Plugins::QNPlugin * const * arNewItems, int newItemsCount,
										  int oldIndex, Neurotec::Plugins::QNPlugin * const * arOldItems, int oldItemsCount, void * pParam)
	{
		QPluginManagerDialog * dialog = (QPluginManagerDialog*)pParam;
		if (action == Neurotec::Collections::nccaAdd)
		{
			for(int i = 0; i < newItemsCount; i++)
			{
				QMetaObject::invokeMethod(dialog, "OnPluginAdded", Qt::QueuedConnection, Q_ARG(Neurotec::Plugins::QNPlugin*, arNewItems[i]));
			}
		}
		Q_UNUSED(pObject);
		Q_UNUSED(newIndex);
		Q_UNUSED(oldIndex);
		Q_UNUSED(arOldItems);
		Q_UNUSED(oldItemsCount);
	}

	static void PuginChanged(Neurotec::QNObject * pObject, Neurotec::QNString propertyName, void * pParam)
	{
		QPluginManagerDialog * dialog = (QPluginManagerDialog*)pParam;
		QMetaObject::invokeMethod(dialog, "OnPluginChanged", Qt::QueuedConnection, Q_ARG(Neurotec::Plugins::QNPlugin*, (Neurotec::Plugins::QNPlugin*)pObject));
		Q_UNUSED(propertyName);
	}

	void OnSelectedPluginChanged()
	{
		QModelIndexList selected = tvPlugins->selectionModel()->selectedIndexes();
		int sc = selected.count();
		Neurotec::Plugins::QNPlugin * plugin = sc == 1 ? (Neurotec::Plugins::QNPlugin*)selected.at(0).data().value<void*>() : NULL;

		QStandardItemModel * model = (QStandardItemModel*)tvActivated->model();
		model->removeRows(0, model->rowCount());
		Neurotec::Plugins::QNPluginModule * module = plugin == NULL? NULL: plugin->GetModule();
		if (module)
		{
			QList<QStandardItem*> row;
			QStringList split = ((QString)module->GetActivated()).split(QRegExp("[:,]"), QString::SkipEmptyParts);
			for(int i = 0; i < split.count() / 2; ++i)
			{
				row.clear();
				row << new QStandardItem(split.at(i*2).trimmed())
					<< new QStandardItem(split.at(i*2 + 1).trimmed());
				model->appendRow(row);
			}
		}
		Neurotec::QNException * error = plugin == NULL? NULL : plugin->GetError();
		teError->setText(error == NULL? QString() : error->ToString());
		if(error) delete error;
		btnUnplug->setEnabled(sc > 0 && pluginManager->AllowsUnplug());
		btnPlug->setEnabled(sc > 0);
		btnEnable->setEnabled(sc > 0);
		btnDisable->setEnabled(sc > 0);
	}

	void OnPluginManagerChanged()
	{
		lblInterfaceTypeValue->setText(pluginManager? pluginManager->GetInterfaceType() : QString());
		lblInterfaceVersionValue->setText(GetInterfaceVersionsString());
		bool enable = pluginManager != NULL;
		lblInterfaceType->setEnabled(enable);
		lblInterfaceVersion->setEnabled(enable);
		tvPlugins->setEnabled(enable);
		lblSearchPath->setEnabled(enable);
		lePath->setEnabled(enable);
		lePath->setReadOnly(true);
		btnBrowse->setEnabled(enable);
		btnUnplugAll->setEnabled(enable && pluginManager->AllowsUnplug());
		btnUnplug->setEnabled(enable && pluginManager->AllowsUnplug());
		btnAdd->setEnabled(enable);
		btnRefresh->setEnabled(enable);
		btnPlugAll->setEnabled(enable);
		OnPluginSearchPathChanged();

		QStandardItemModel * model = (QStandardItemModel*)tvPlugins->model();
		model->removeRows(0, model->rowCount());
		if(pluginManager)
		{
			int count;
			Neurotec::Plugins::QNPlugin ** arPlugins = pluginManager->GetPlugins()->ToArray(&count);
			auto_array<Neurotec::Plugins::QNPlugin*> plugins(arPlugins, count);
			for(int i = 0; i < count; i++)
			{
				AddPlugin(plugins[i]);
			}

			if(count != 0)
			{
				tvPlugins->resizeColumnToContents(0);
				tvPlugins->resizeColumnToContents(1);
			}
			pluginManager->GetDisabledPlugins()->AddCollectionChangedCallback(PluginManager_DisabledPluginCanged, this);
			pluginManager->GetPlugins()->AddCollectionChangedCallback(PluginManager_PluginAdded, this);
		}

		UpdateTotalInfo();
		OnSelectedPluginChanged();
	}

	void OnPluginSearchPathChanged()
	{
		lePath->setText(pluginManager == NULL? QString() : pluginManager->GetPluginSearchPath());
		lePath->setReadOnly(true);
	}

	QString GetModuleVersion(Neurotec::QNModule * module)
	{
		if(!module) return QString::null;
		return QString("%1.%2.%3.%4").arg(QString::number(module->GetVersionMajor()), QString::number(module->GetVersionMinor()),
										  QString::number(module->GetVersionBuild()), QString::number(module->GetVersionRevision()));
	}

	static QString NModuleOptionsToString(Neurotec::NModuleOptions options)
	{
		QString value = QString();
		if((options & Neurotec::nmoDebug) == Neurotec::nmoDebug)
			value = "Debug";
		if((options & Neurotec::nmoProtected) == Neurotec::nmoProtected)
		{
			value = value.isEmpty()? value : value.append(", ");
			value.append("Protected");
		}
		if((options & Neurotec::nmoUnicode) == Neurotec::nmoUnicode)
		{
			value = value.isEmpty()? value : value.append(", ");
			value.append("Unicode");
		}
		if((options & Neurotec::nmoNoAnsiFunc) == Neurotec::nmoNoAnsiFunc)
		{
			value = value.isEmpty()? value : value.append(", ");
			value.append("NoAnsiFunc");
		}
		if((options & Neurotec::nmoNoUnicode) == Neurotec::nmoNoUnicode)
		{
			value = value.isEmpty()? value : value.append(", ");
			value.append("NoUnicode");
		}
		if((options & Neurotec::nmoLib) == Neurotec::nmoLib)
		{
			value = value.isEmpty()? value : value.append(", ");
			value.append("Lib");
		}
		if((options & Neurotec::nmoExe) == Neurotec::nmoExe)
		{
			value = value.isEmpty()? value : value.append(", ");
			value.append("Exe");
		}

		return value.isEmpty()? "None" : value;
	}

	static QString NPluginStateToString(Neurotec::Plugins::NPluginState state)
	{
		switch(state)
		{
		case Neurotec::Plugins::npsNone: return "None";
		case Neurotec::Plugins::npsLoadError: return "LoadError";
		case Neurotec::Plugins::npsNotRecognized: return "NotRecognized";
		case Neurotec::Plugins::npsInvalidModule: return "InvalidModule";
		case Neurotec::Plugins::npsInterfaceTypeMismatch: return "InterfaceTypeMismatch";
		case Neurotec::Plugins::npsInterfaceVersionMismatch: return "InterfaceVersionMismatch";
		case Neurotec::Plugins::npsInvalidInterface: return "InvalidInterface";
		case Neurotec::Plugins::npsUnplugged: return "Unplugged";
		case Neurotec::Plugins::npsUnused: return "Unused";
		case Neurotec::Plugins::npsDisabled: return "Disabled";
		case Neurotec::Plugins::npsDuplicate: return "Duplicate";
		case Neurotec::Plugins::npsIncompatibleWithOtherPlugins: return "IncompatibleWithOtherPlugins";
		case Neurotec::Plugins::npsPluggingError: return "PluggingError";
		case Neurotec::Plugins::npsPlugged: return "Plugged";
		default: return "Unknown";
		}
	}

	static QTime QTimeAdd(QTime time1, QTime time2)
	{
		QTime result = time1.addSecs(time2.hour() * 3600 + time2.minute() * 60 + time2.second());
		return result.addMSecs(time2.msec());
	}

	static double QTimeTotalSeconds(QTime time)
	{
		return time.hour() * 3600 + time.minute() * 60 + time.second() + time.msec() / 1000.0;
	}

private slots:
	void UpdateTotalInfo()
	{
		if (pluginManager)
		{
			QTime loadTime(0, 0);
			QTime plugTime(0, 0);
			int unpluggedCount = 0;
			int unusedCount = 0;
			QStandardItemModel * model = (QStandardItemModel*)tvPlugins->model();
			int count = model->rowCount();
			for(int i = 0; i < count; i++)
			{
				Neurotec::Plugins::QNPlugin * plugin = (Neurotec::Plugins::QNPlugin*)model->item(i)->data().value<void*>();
				loadTime = QTimeAdd(loadTime, plugin->GetLoadTime());
				plugTime = QTimeAdd(plugTime, plugin->GetPlugTime());
				if (plugin->GetState() == Neurotec::Plugins::npsUnplugged) unpluggedCount++;
				else if (plugin->GetState() == Neurotec::Plugins::npsUnused) unusedCount++;
			}

			QString disabledPlugins;
			{
				int disabledPluginsCount;
				QNString * arDisabledPlugins = pluginManager->GetDisabledPlugins()->ToArray(&disabledPluginsCount);
				auto_array<QNString> plugins(arDisabledPlugins, disabledPluginsCount);
				for(int i = 0; i < disabledPluginsCount; i++)
				{
					disabledPlugins.append(disabledPlugins.size() == 0? ". Disabled: " : ", ");
					disabledPlugins.append(plugins[i]);
				}
			}
			QTime totalTime = QTimeAdd(loadTime, plugTime);
			QString parse = QString("Total time: %1 s (Load: %2 s. Plug: %3 s). Total plugins: %4 (Unplugged: %5. Unused: %6)%7");
			parse = parse.arg(QString::number(QTimeTotalSeconds(totalTime), 'g', 2),
							  QString::number(QTimeTotalSeconds(loadTime), 'g', 2),
							  QString::number(QTimeTotalSeconds(plugTime), 'g', 2),
							  QString::number(count),
							  QString::number(unpluggedCount),
							  QString::number(unusedCount),
							  disabledPlugins);
			lblTotalInfo->setText(parse);
		}
		else
		{
			lblTotalInfo->setText(QString());
		}
	}

	void OnSetSelectedPlugin(Neurotec::Plugins::QNPlugin* select)
	{
		if(thread() != QThread::currentThread())
		{
			QMetaObject::invokeMethod(this, "OnSetSelectedPlugin", Qt::BlockingQueuedConnection, Q_ARG(Neurotec::Plugins::QNPlugin*, select));
			return;
		}
		tvPlugins->selectionModel()->clearSelection();
		if(select)
		{
			QStandardItemModel * model = (QStandardItemModel*)tvPlugins->model();
			for(int i = 0; i < model->rowCount(); i++)
			{
				QStandardItem * item = model->item(i);
				Neurotec::Plugins::QNPlugin * plugin = (Neurotec::Plugins::QNPlugin*)item->data().value<void*>();
				if(plugin->Equals(select))
				{
					tvPlugins->selectionModel()->select(item->index(), QItemSelectionModel::Select | QItemSelectionModel::Rows);
					tvPlugins->scrollTo(item->index());
					OnPluginClick(item->index());
					break;
				}
			}
		}
	}

	void OnDisabledPluginsChanged()
	{
		UpdateTotalInfo();
	}

	void OnPluginChanged(Neurotec::Plugins::QNPlugin * plugin)
	{
		UpdatePlugin(plugin);
	}

	void OnPluginAdded(Neurotec::Plugins::QNPlugin * plugin)
	{
		if (plugin)
		{
			QStandardItemModel * model = (QStandardItemModel*)tvPlugins->model();
			for(int i = 0; i < model->rowCount(); i++)
			{
				QStandardItem * item = model->item(i);
				Neurotec::Plugins::QNPlugin * p = (Neurotec::Plugins::QNPlugin*)item->data().value<void*>();
				if(plugin->Equals(p)) return; // Plugin is already added
			}

			AddPlugin(plugin);
			OnSetSelectedPlugin(plugin);
			UpdateTotalInfo();
		}
	}

	void OnPluginClick(QModelIndex)
	{
		OnSelectedPluginChanged();
	}

	void OnBtnBrowseClick()
	{
		if(pluginManager)
		{
			QString folder = QFileDialog::getExistingDirectory(this, "Select folder", pluginManager->GetPluginSearchPath());
			if(!folder.isNull())
			{
				pluginManager->SetPluginSearchPath(folder);
				OnPluginSearchPathChanged();
			}
		}
	}

	void OnBtnAddClick()
	{
		if(!pluginManager) return;

		QStringList files = QFileDialog::getOpenFileNames(this);
		if(files.count() > 0)
		{
			this->setEnabled(false);
			try
			{
				for(int i = 0; i < files.count(); i++)
				{
					AsyncRun::AddPluginAsync(pluginManager, files.at(i), this);
				}
			}
			catch(...)
			{
				this->setEnabled(true);
			}
			this->setEnabled(true);
		}
	}

	void OnBtnRefreshClick()
	{
		if(!pluginManager) return;
		AsyncRun::RefreshAsync(pluginManager, this);
	}

	void OnBtnPlugAllClick()
	{
		if(!pluginManager) return;
		AsyncRun::PlugAllAsync(pluginManager, this);
	}

	void OnBtnUnplugAllClick()
	{
		if(!pluginManager) return;
		AsyncRun::UnplugAllAsync(pluginManager, this);
	}

	void OnBtnPlugClick()
	{
		try
		{
			this->setEnabled(false);
			QStandardItemModel * model = (QStandardItemModel*)tvPlugins->model();
			QModelIndexList selected = tvPlugins->selectionModel()->selection().indexes();
			for(int i = 0; i < selected.count(); i++)
			{
				QStandardItem* item = model->item(selected.at(i).row());
				Neurotec::Plugins::QNPlugin * plugin = (Neurotec::Plugins::QNPlugin*)item->data().value<void*>();
				AsyncRun::PlugAsync(plugin, this);
			}
		}
		catch(...)
		{
			this->setEnabled(true);
			throw;
		}
		this->setEnabled(true);
	}

	void OnBtnEnableClick()
	{
		try
		{
			this->setEnabled(false);
			QModelIndexList selected = tvPlugins->selectionModel()->selection().indexes();
			QStandardItemModel * model = (QStandardItemModel*)tvPlugins->model();
			for(int i = 0; i < selected.count(); i++)
			{
				QStandardItem * item = model->item(selected.at(i).row());
				Neurotec::Plugins::QNPlugin * plugin = (Neurotec::Plugins::QNPlugin*)item->data().value<void*>();
				AsyncRun::EbableAsync(plugin, this);
			}
		}
		catch(...)
		{
			this->setEnabled(false);
			throw;
		}
		this->setEnabled(true);
	}

	void OnBtnDisableClick()
	{
		try
		{
			this->setEnabled(false);
			QModelIndexList selected = tvPlugins->selectionModel()->selection().indexes();
			QStandardItemModel * model = (QStandardItemModel*)tvPlugins->model();
			for(int i = 0; i < selected.count(); i++)
			{
				QStandardItem* item = model->item(selected.at(i).row());
				Neurotec::Plugins::QNPlugin * plugin = (Neurotec::Plugins::QNPlugin*)item->data().value<void*>();
				AsyncRun::DisableAsync(plugin, this);
			}
		}
		catch(...)
		{
			this->setEnabled(false);
			throw;
		}
		this->setEnabled(true);
	}

	void OnBtnUnplugClick()
	{
		try
		{
			this->setEnabled(false);
			QModelIndexList selected = tvPlugins->selectionModel()->selection().indexes();
			QStandardItemModel * model = (QStandardItemModel*)tvPlugins->model();
			for(int i = 0; i < selected.count(); i++)
			{
				QStandardItem * item = model->item(selected.at(i).row());
				Neurotec::Plugins::QNPlugin * plugin = (Neurotec::Plugins::QNPlugin*)item->data().value<void*>();
				AsyncRun::UnplugAsync(plugin, this);
			}
		}
		catch(...)
		{
			this->setEnabled(true);
			throw;
		}
		this->setEnabled(true);
	}
};

}}
#endif // QT_PLUGINMANAGERDIALOG_HPP_INCLUDED
