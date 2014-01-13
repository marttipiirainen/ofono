/*
 *
 *  oFono - Open Source Telephony
 *
 *  Copyright (C) 2014 Jolla. All rights reserved.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <glib.h>
struct ofono_modem;
#include <gprs-provision.h>
#include "plugins/mbpi.h"
#include "plugins/provision.h"

static void test_get_settings(void)
{
	struct ofono_gprs_provision_data *settings;
	int count;
	int i;
	provision_get_settings("244", "91", NULL, &settings, &count);
	g_print("Settings found for 244/91/NULL: %d\n", count);
	for (i = 0; i < count; i++){
		struct ofono_gprs_provision_data ap = settings[i];
		g_print("  Name: %s\n", ap.name);
		g_print("  APN: %s\n", ap.apn);
		g_print("  Type: %s\n", mbpi_ap_type(ap.type));
		g_print("  Username: %s\n", ap.username);
		g_print("  Password: %s\n", ap.password);
		g_print("  MMS proxy: %s\n", ap.message_proxy);
		g_print("  MMS center: %s\n", ap.message_center);
	}
}


int main(int argc, char **argv)
{
	g_test_init(&argc, &argv, NULL);
	g_test_add_func("/testprovision/get_settings", test_get_settings);
	return g_test_run();
}
