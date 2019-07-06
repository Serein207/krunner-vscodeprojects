/******************************************************************************
 *   Copyright %{CURRENT_YEAR} by %{AUTHOR} <%{EMAIL}>                        *
 *                                                                            *
 *  This library is free software; you can redistribute it and/or modify      *
 *  it under the terms of the GNU Lesser General Public License as published  *
 *  by the Free Software Foundation; either version 2 of the License or (at   *
 *  your option) any later version.                                           *
 *                                                                            *
 *  This library is distributed in the hope that it will be useful,           *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU         *
 *  Library General Public License for more details.                          *
 *                                                                            *
 *  You should have received a copy of the GNU Lesser General Public License  *
 *  along with this library; see the file COPYING.LIB.                        *
 *  If not, see <http://www.gnu.org/licenses/>.                               *
 *****************************************************************************/

#include "vscodeprojectsrunner_config.h"
#include <KSharedConfig>
#include <KPluginFactory>
#include <krunner/abstractrunner.h>

K_PLUGIN_FACTORY(VSCodeProjectsRunnerConfigFactory, registerPlugin<VSCodeProjectsRunnerConfig>("kcm_krunner_vscodeprojectsrunner");)

VSCodeProjectsRunnerConfigForm::VSCodeProjectsRunnerConfigForm(QWidget *parent) : QWidget(parent) {
    setupUi(this);
}

VSCodeProjectsRunnerConfig::VSCodeProjectsRunnerConfig(QWidget *parent, const QVariantList &args) : KCModule(parent, args) {
    m_ui = new VSCodeProjectsRunnerConfigForm(this);
    auto *layout = new QGridLayout(this);
    layout->addWidget(m_ui, 0, 0);
    load();

}

void VSCodeProjectsRunnerConfig::load() {
    KCModule::load();
    
    emit changed(false);
}


void VSCodeProjectsRunnerConfig::save() {

    KCModule::save();

    emit changed();
}

void VSCodeProjectsRunnerConfig::defaults() {
    
    emit changed(true);
}


#include "vscodeprojectsrunner_config.moc"
