/* player-controller.c generated by valac 0.11.7, the Vala compiler
 * generated from player-controller.vala, do not modify */

/*
This service primarily controls PulseAudio and is driven by the sound indicator menu on the panel.
Copyright 2010 Canonical Ltd.

Authors:
    Conor Curran <conor.curran@canonical.com>

This program is free software: you can redistribute it and/or modify it 
under the terms of the GNU General Public License version 3, as published 
by the Free Software Foundation.

This program is distributed in the hope that it will be useful, but 
WITHOUT ANY WARRANTY; without even the implied warranties of 
MERCHANTABILITY, SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR 
PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along 
with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <glib.h>
#include <glib-object.h>
#include <gee.h>
#include <libdbusmenu-glib/client.h>
#include <libdbusmenu-glib/dbusmenu-glib.h>
#include <libdbusmenu-glib/enum-types.h>
#include <libdbusmenu-glib/menuitem-proxy.h>
#include <libdbusmenu-glib/menuitem.h>
#include <libdbusmenu-glib/server.h>
#include <libdbusmenu-glib/types.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>


#define TYPE_PLAYER_CONTROLLER (player_controller_get_type ())
#define PLAYER_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PLAYER_CONTROLLER, PlayerController))
#define PLAYER_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PLAYER_CONTROLLER, PlayerControllerClass))
#define IS_PLAYER_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PLAYER_CONTROLLER))
#define IS_PLAYER_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PLAYER_CONTROLLER))
#define PLAYER_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PLAYER_CONTROLLER, PlayerControllerClass))

typedef struct _PlayerController PlayerController;
typedef struct _PlayerControllerClass PlayerControllerClass;
typedef struct _PlayerControllerPrivate PlayerControllerPrivate;

#define TYPE_PLAYER_ITEM (player_item_get_type ())
#define PLAYER_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PLAYER_ITEM, PlayerItem))
#define PLAYER_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PLAYER_ITEM, PlayerItemClass))
#define IS_PLAYER_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PLAYER_ITEM))
#define IS_PLAYER_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PLAYER_ITEM))
#define PLAYER_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PLAYER_ITEM, PlayerItemClass))

typedef struct _PlayerItem PlayerItem;
typedef struct _PlayerItemClass PlayerItemClass;

#define TYPE_MPRIS2_CONTROLLER (mpris2_controller_get_type ())
#define MPRIS2_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_MPRIS2_CONTROLLER, Mpris2Controller))
#define MPRIS2_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_MPRIS2_CONTROLLER, Mpris2ControllerClass))
#define IS_MPRIS2_CONTROLLER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_MPRIS2_CONTROLLER))
#define IS_MPRIS2_CONTROLLER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_MPRIS2_CONTROLLER))
#define MPRIS2_CONTROLLER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_MPRIS2_CONTROLLER, Mpris2ControllerClass))

typedef struct _Mpris2Controller Mpris2Controller;
typedef struct _Mpris2ControllerClass Mpris2ControllerClass;

#define PLAYER_CONTROLLER_TYPE_WIDGET_ORDER (player_controller_widget_order_get_type ())

#define PLAYER_CONTROLLER_TYPE_STATE (player_controller_state_get_type ())
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

#define TYPE_PLAYLISTS_MENUITEM (playlists_menuitem_get_type ())
#define PLAYLISTS_MENUITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_PLAYLISTS_MENUITEM, PlaylistsMenuitem))
#define PLAYLISTS_MENUITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_PLAYLISTS_MENUITEM, PlaylistsMenuitemClass))
#define IS_PLAYLISTS_MENUITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_PLAYLISTS_MENUITEM))
#define IS_PLAYLISTS_MENUITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_PLAYLISTS_MENUITEM))
#define PLAYLISTS_MENUITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_PLAYLISTS_MENUITEM, PlaylistsMenuitemClass))

typedef struct _PlaylistsMenuitem PlaylistsMenuitem;
typedef struct _PlaylistsMenuitemClass PlaylistsMenuitemClass;
typedef struct _PlayerItemPrivate PlayerItemPrivate;
typedef struct _PlaylistsMenuitemPrivate PlaylistsMenuitemPrivate;

#define TYPE_TITLE_MENUITEM (title_menuitem_get_type ())
#define TITLE_MENUITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TITLE_MENUITEM, TitleMenuitem))
#define TITLE_MENUITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_TITLE_MENUITEM, TitleMenuitemClass))
#define IS_TITLE_MENUITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TITLE_MENUITEM))
#define IS_TITLE_MENUITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_TITLE_MENUITEM))
#define TITLE_MENUITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TITLE_MENUITEM, TitleMenuitemClass))

typedef struct _TitleMenuitem TitleMenuitem;
typedef struct _TitleMenuitemClass TitleMenuitemClass;

#define TYPE_METADATA_MENUITEM (metadata_menuitem_get_type ())
#define METADATA_MENUITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_METADATA_MENUITEM, MetadataMenuitem))
#define METADATA_MENUITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_METADATA_MENUITEM, MetadataMenuitemClass))
#define IS_METADATA_MENUITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_METADATA_MENUITEM))
#define IS_METADATA_MENUITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_METADATA_MENUITEM))
#define METADATA_MENUITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_METADATA_MENUITEM, MetadataMenuitemClass))

typedef struct _MetadataMenuitem MetadataMenuitem;
typedef struct _MetadataMenuitemClass MetadataMenuitemClass;

#define TYPE_TRANSPORT_MENUITEM (transport_menuitem_get_type ())
#define TRANSPORT_MENUITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_TRANSPORT_MENUITEM, TransportMenuitem))
#define TRANSPORT_MENUITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_TRANSPORT_MENUITEM, TransportMenuitemClass))
#define IS_TRANSPORT_MENUITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_TRANSPORT_MENUITEM))
#define IS_TRANSPORT_MENUITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_TRANSPORT_MENUITEM))
#define TRANSPORT_MENUITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_TRANSPORT_MENUITEM, TransportMenuitemClass))

typedef struct _TransportMenuitem TransportMenuitem;
typedef struct _TransportMenuitemClass TransportMenuitemClass;

struct _PlayerController {
	GObject parent_instance;
	PlayerControllerPrivate * priv;
	gint current_state;
	GeeArrayList* custom_items;
	Mpris2Controller* mpris_bridge;
	gboolean* use_playlists;
};

struct _PlayerControllerClass {
	GObjectClass parent_class;
};

struct _PlayerControllerPrivate {
	DbusmenuMenuitem* root_menu;
	gchar* _dbus_name;
	GAppInfo* _app_info;
	gint _menu_offset;
	gchar* _icon_name;
};

typedef enum  {
	PLAYER_CONTROLLER_WIDGET_ORDER_SEPARATOR,
	PLAYER_CONTROLLER_WIDGET_ORDER_TITLE,
	PLAYER_CONTROLLER_WIDGET_ORDER_METADATA,
	PLAYER_CONTROLLER_WIDGET_ORDER_TRANSPORT,
	PLAYER_CONTROLLER_WIDGET_ORDER_PLAYLISTS
} PlayerControllerwidget_order;

typedef enum  {
	PLAYER_CONTROLLER_STATE_OFFLINE,
	PLAYER_CONTROLLER_STATE_INSTANTIATING,
	PLAYER_CONTROLLER_STATE_READY,
	PLAYER_CONTROLLER_STATE_CONNECTED,
	PLAYER_CONTROLLER_STATE_DISCONNECTED
} PlayerControllerstate;

struct _PlayerItem {
	DbusmenuMenuitem parent_instance;
	PlayerItemPrivate * priv;
};

struct _PlayerItemClass {
	DbusmenuMenuitemClass parent_class;
};

struct _PlaylistsMenuitem {
	PlayerItem parent_instance;
	PlaylistsMenuitemPrivate * priv;
	DbusmenuMenuitem* root_item;
};

struct _PlaylistsMenuitemClass {
	PlayerItemClass parent_class;
};


static gpointer player_controller_parent_class = NULL;

GType player_controller_get_type (void) G_GNUC_CONST;
GType player_item_get_type (void) G_GNUC_CONST;
GType mpris2_controller_get_type (void) G_GNUC_CONST;
#define PLAYER_CONTROLLER_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), TYPE_PLAYER_CONTROLLER, PlayerControllerPrivate))
enum  {
	PLAYER_CONTROLLER_DUMMY_PROPERTY,
	PLAYER_CONTROLLER_DBUS_NAME,
	PLAYER_CONTROLLER_APP_INFO,
	PLAYER_CONTROLLER_MENU_OFFSET,
	PLAYER_CONTROLLER_ICON_NAME
};
GType player_controller_widget_order_get_type (void) G_GNUC_CONST;
GType player_controller_state_get_type (void) G_GNUC_CONST;
#define PLAYER_CONTROLLER_WIDGET_QUANTITY 5
PlayerController* player_controller_new (DbusmenuMenuitem* root, GAppInfo* app, const gchar* dbus_name, const gchar* icon_name, gint offset, gboolean* use_playlists, PlayerControllerstate initial_state);
PlayerController* player_controller_construct (GType object_type, DbusmenuMenuitem* root, GAppInfo* app, const gchar* dbus_name, const gchar* icon_name, gint offset, gboolean* use_playlists, PlayerControllerstate initial_state);
static gboolean* _bool_dup (gboolean* self);
void player_controller_set_app_info (PlayerController* self, GAppInfo* value);
void player_controller_set_dbus_name (PlayerController* self, const gchar* value);
void player_controller_set_icon_name (PlayerController* self, const gchar* value);
void player_controller_set_menu_offset (PlayerController* self, gint value);
static void player_controller_construct_widgets (PlayerController* self);
static void player_controller_establish_mpris_connection (PlayerController* self);
void player_controller_update_layout (PlayerController* self);
void player_controller_update_state (PlayerController* self, PlayerControllerstate new_state);
GAppInfo* player_controller_get_app_info (PlayerController* self);
void player_controller_activate (PlayerController* self, const gchar* dbus_name);
void player_controller_instantiate (PlayerController* self);
const gchar* player_controller_get_dbus_name (PlayerController* self);
Mpris2Controller* mpris2_controller_new (PlayerController* ctrl);
Mpris2Controller* mpris2_controller_construct (GType object_type, PlayerController* ctrl);
static void player_controller_determine_state (PlayerController* self);
void player_controller_remove_from_menu (PlayerController* self);
static gboolean _bool_equal (const gboolean* s1, const gboolean* s2);
GType playlists_menuitem_get_type (void) G_GNUC_CONST;
void player_controller_hibernate (PlayerController* self);
void player_item_reset (PlayerItem* self, GeeHashSet* attrs);
GeeHashSet* transport_menuitem_attributes_format (void);
GeeHashSet* metadata_menuitem_attributes_format (void);
GType title_menuitem_get_type (void) G_GNUC_CONST;
void title_menuitem_toggle_active_triangle (TitleMenuitem* self, gboolean update);
gboolean player_item_populated (PlayerItem* self, GeeHashSet* attrs);
PlayerItem* player_item_new (const gchar* type);
PlayerItem* player_item_construct (GType object_type, const gchar* type);
TitleMenuitem* title_menuitem_new (PlayerController* parent);
TitleMenuitem* title_menuitem_construct (GType object_type, PlayerController* parent);
MetadataMenuitem* metadata_menuitem_new (void);
MetadataMenuitem* metadata_menuitem_construct (GType object_type);
GType metadata_menuitem_get_type (void) G_GNUC_CONST;
TransportMenuitem* transport_menuitem_new (PlayerController* parent);
TransportMenuitem* transport_menuitem_construct (GType object_type, PlayerController* parent);
GType transport_menuitem_get_type (void) G_GNUC_CONST;
PlaylistsMenuitem* playlists_menuitem_new (PlayerController* parent);
PlaylistsMenuitem* playlists_menuitem_construct (GType object_type, PlayerController* parent);
gint player_controller_get_menu_offset (PlayerController* self);
gboolean mpris2_controller_connected (Mpris2Controller* self);
void mpris2_controller_initial_update (Mpris2Controller* self);
const gchar* player_controller_get_icon_name (PlayerController* self);
static void player_controller_finalize (GObject* obj);
static void _vala_player_controller_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_player_controller_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


GType player_controller_widget_order_get_type (void) {
	static volatile gsize player_controller_widget_order_type_id__volatile = 0;
	if (g_once_init_enter (&player_controller_widget_order_type_id__volatile)) {
		static const GEnumValue values[] = {{PLAYER_CONTROLLER_WIDGET_ORDER_SEPARATOR, "PLAYER_CONTROLLER_WIDGET_ORDER_SEPARATOR", "separator"}, {PLAYER_CONTROLLER_WIDGET_ORDER_TITLE, "PLAYER_CONTROLLER_WIDGET_ORDER_TITLE", "title"}, {PLAYER_CONTROLLER_WIDGET_ORDER_METADATA, "PLAYER_CONTROLLER_WIDGET_ORDER_METADATA", "metadata"}, {PLAYER_CONTROLLER_WIDGET_ORDER_TRANSPORT, "PLAYER_CONTROLLER_WIDGET_ORDER_TRANSPORT", "transport"}, {PLAYER_CONTROLLER_WIDGET_ORDER_PLAYLISTS, "PLAYER_CONTROLLER_WIDGET_ORDER_PLAYLISTS", "playlists"}, {0, NULL, NULL}};
		GType player_controller_widget_order_type_id;
		player_controller_widget_order_type_id = g_enum_register_static ("PlayerControllerwidget_order", values);
		g_once_init_leave (&player_controller_widget_order_type_id__volatile, player_controller_widget_order_type_id);
	}
	return player_controller_widget_order_type_id__volatile;
}


GType player_controller_state_get_type (void) {
	static volatile gsize player_controller_state_type_id__volatile = 0;
	if (g_once_init_enter (&player_controller_state_type_id__volatile)) {
		static const GEnumValue values[] = {{PLAYER_CONTROLLER_STATE_OFFLINE, "PLAYER_CONTROLLER_STATE_OFFLINE", "offline"}, {PLAYER_CONTROLLER_STATE_INSTANTIATING, "PLAYER_CONTROLLER_STATE_INSTANTIATING", "instantiating"}, {PLAYER_CONTROLLER_STATE_READY, "PLAYER_CONTROLLER_STATE_READY", "ready"}, {PLAYER_CONTROLLER_STATE_CONNECTED, "PLAYER_CONTROLLER_STATE_CONNECTED", "connected"}, {PLAYER_CONTROLLER_STATE_DISCONNECTED, "PLAYER_CONTROLLER_STATE_DISCONNECTED", "disconnected"}, {0, NULL, NULL}};
		GType player_controller_state_type_id;
		player_controller_state_type_id = g_enum_register_static ("PlayerControllerstate", values);
		g_once_init_leave (&player_controller_state_type_id__volatile, player_controller_state_type_id);
	}
	return player_controller_state_type_id__volatile;
}


static gboolean* _bool_dup (gboolean* self) {
	gboolean* dup;
	dup = g_new0 (gboolean, 1);
	memcpy (dup, self, sizeof (gboolean));
	return dup;
}


static gpointer __bool_dup0 (gpointer self) {
	return self ? _bool_dup (self) : NULL;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


PlayerController* player_controller_construct (GType object_type, DbusmenuMenuitem* root, GAppInfo* app, const gchar* dbus_name, const gchar* icon_name, gint offset, gboolean* use_playlists, PlayerControllerstate initial_state) {
	PlayerController * self = NULL;
	gboolean* _tmp0_;
	DbusmenuMenuitem* _tmp1_;
	GeeArrayList* _tmp2_ = NULL;
	g_return_val_if_fail (root != NULL, NULL);
	g_return_val_if_fail (app != NULL, NULL);
	g_return_val_if_fail (icon_name != NULL, NULL);
	self = (PlayerController*) g_object_new (object_type, NULL);
	_tmp0_ = __bool_dup0 (use_playlists);
	_g_free0 (self->use_playlists);
	self->use_playlists = _tmp0_;
	_tmp1_ = _g_object_ref0 (root);
	_g_object_unref0 (self->priv->root_menu);
	self->priv->root_menu = _tmp1_;
	player_controller_set_app_info (self, app);
	player_controller_set_dbus_name (self, dbus_name);
	player_controller_set_icon_name (self, icon_name);
	_tmp2_ = gee_array_list_new (TYPE_PLAYER_ITEM, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL);
	_g_object_unref0 (self->custom_items);
	self->custom_items = _tmp2_;
	self->current_state = (gint) initial_state;
	player_controller_set_menu_offset (self, offset);
	player_controller_construct_widgets (self);
	player_controller_establish_mpris_connection (self);
	player_controller_update_layout (self);
	return self;
}


PlayerController* player_controller_new (DbusmenuMenuitem* root, GAppInfo* app, const gchar* dbus_name, const gchar* icon_name, gint offset, gboolean* use_playlists, PlayerControllerstate initial_state) {
	return player_controller_construct (TYPE_PLAYER_CONTROLLER, root, app, dbus_name, icon_name, offset, use_playlists, initial_state);
}


void player_controller_update_state (PlayerController* self, PlayerControllerstate new_state) {
	const gchar* _tmp0_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_app_info_get_name (self->priv->_app_info);
	g_debug ("player-controller.vala:78: update_state - player controller %s : new s" \
"tate %i", _tmp0_, (gint) new_state);
	self->current_state = (gint) new_state;
	player_controller_update_layout (self);
}


void player_controller_activate (PlayerController* self, const gchar* dbus_name) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (dbus_name != NULL);
	player_controller_set_dbus_name (self, dbus_name);
	player_controller_establish_mpris_connection (self);
}


void player_controller_instantiate (PlayerController* self) {
	const gchar* _tmp0_ = NULL;
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_app_info_get_name (self->priv->_app_info);
	g_debug ("player-controller.vala:98: instantiate in player controller for %s", _tmp0_);
	g_app_info_launch (self->priv->_app_info, NULL, NULL, &_inner_error_);
	if (_inner_error_ != NULL) {
		goto __catch6_g_error;
	}
	player_controller_update_state (self, PLAYER_CONTROLLER_STATE_INSTANTIATING);
	goto __finally6;
	__catch6_g_error:
	{
		GError * _error_;
		const gchar* _tmp1_ = NULL;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		_tmp1_ = g_app_info_get_name (self->priv->_app_info);
		g_warning ("player-controller.vala:104: Failed to launch app %s with error message" \
": %s", _tmp1_, _error_->message);
		_g_error_free0 (_error_);
	}
	__finally6:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


static gchar* bool_to_string (gboolean self) {
	gchar* result = NULL;
	if (self) {
		gchar* _tmp0_;
		_tmp0_ = g_strdup ("true");
		result = _tmp0_;
		return result;
	} else {
		gchar* _tmp1_;
		_tmp1_ = g_strdup ("false");
		result = _tmp1_;
		return result;
	}
}


static void player_controller_establish_mpris_connection (PlayerController* self) {
	gboolean _tmp0_ = FALSE;
	gchar* _tmp1_ = NULL;
	gchar* _tmp2_;
	Mpris2Controller* _tmp3_ = NULL;
	g_return_if_fail (self != NULL);
	if (self->current_state != PLAYER_CONTROLLER_STATE_READY) {
		_tmp0_ = TRUE;
	} else {
		_tmp0_ = self->priv->_dbus_name == NULL;
	}
	if (_tmp0_) {
		g_debug ("player-controller.vala:112: establish_mpris_connection - Not ready to " \
"connect");
		return;
	}
	_tmp1_ = bool_to_string (*self->use_playlists);
	_tmp2_ = _tmp1_;
	g_debug ("player-controller.vala:115:  establish mpris connection - use playlist" \
"s value = %s ", _tmp2_);
	_g_free0 (_tmp2_);
	_tmp3_ = mpris2_controller_new (self);
	_g_object_unref0 (self->mpris_bridge);
	self->mpris_bridge = _tmp3_;
	player_controller_determine_state (self);
}


static gboolean _bool_equal (const gboolean* s1, const gboolean* s2) {
	if (s1 == s2) {
		return TRUE;
	}
	if (s1 == NULL) {
		return FALSE;
	}
	if (s2 == NULL) {
		return FALSE;
	}
	return (*s1) == (*s2);
}


void player_controller_remove_from_menu (PlayerController* self) {
	gboolean _tmp3_;
	g_return_if_fail (self != NULL);
	{
		GeeArrayList* _tmp0_;
		GeeArrayList* _item_list;
		gint _tmp1_;
		gint _item_size;
		gint _item_index;
		_tmp0_ = _g_object_ref0 (self->custom_items);
		_item_list = _tmp0_;
		_tmp1_ = gee_collection_get_size ((GeeCollection*) _item_list);
		_item_size = _tmp1_;
		_item_index = -1;
		while (TRUE) {
			gpointer _tmp2_ = NULL;
			PlayerItem* item;
			_item_index = _item_index + 1;
			if (!(_item_index < _item_size)) {
				break;
			}
			_tmp2_ = gee_abstract_list_get ((GeeAbstractList*) _item_list, _item_index);
			item = (PlayerItem*) _tmp2_;
			dbusmenu_menuitem_child_delete (self->priv->root_menu, (DbusmenuMenuitem*) item);
			_g_object_unref0 (item);
		}
		_g_object_unref0 (_item_list);
	}
	_tmp3_ = TRUE;
	if (_bool_equal (self->use_playlists, &_tmp3_) == TRUE) {
		gpointer _tmp4_ = NULL;
		PlayerItem* _tmp5_;
		PlaylistsMenuitem* playlists_menuitem;
		_tmp4_ = gee_abstract_list_get ((GeeAbstractList*) self->custom_items, (gint) PLAYER_CONTROLLER_WIDGET_ORDER_PLAYLISTS);
		_tmp5_ = (PlayerItem*) _tmp4_;
		playlists_menuitem = IS_PLAYLISTS_MENUITEM (_tmp5_) ? ((PlaylistsMenuitem*) _tmp5_) : NULL;
		dbusmenu_menuitem_child_delete (self->priv->root_menu, playlists_menuitem->root_item);
		_g_object_unref0 (playlists_menuitem);
	}
}


void player_controller_hibernate (PlayerController* self) {
	gpointer _tmp0_ = NULL;
	PlayerItem* _tmp1_;
	GeeHashSet* _tmp2_ = NULL;
	GeeHashSet* _tmp3_;
	gpointer _tmp4_ = NULL;
	PlayerItem* _tmp5_;
	GeeHashSet* _tmp6_ = NULL;
	GeeHashSet* _tmp7_;
	gpointer _tmp8_ = NULL;
	PlayerItem* _tmp9_;
	TitleMenuitem* title;
	g_return_if_fail (self != NULL);
	player_controller_update_state (self, PLAYER_CONTROLLER_STATE_OFFLINE);
	_tmp0_ = gee_abstract_list_get ((GeeAbstractList*) self->custom_items, (gint) PLAYER_CONTROLLER_WIDGET_ORDER_TRANSPORT);
	_tmp1_ = (PlayerItem*) _tmp0_;
	_tmp2_ = transport_menuitem_attributes_format ();
	_tmp3_ = _tmp2_;
	player_item_reset (_tmp1_, _tmp3_);
	_g_object_unref0 (_tmp3_);
	_g_object_unref0 (_tmp1_);
	_tmp4_ = gee_abstract_list_get ((GeeAbstractList*) self->custom_items, (gint) PLAYER_CONTROLLER_WIDGET_ORDER_METADATA);
	_tmp5_ = (PlayerItem*) _tmp4_;
	_tmp6_ = metadata_menuitem_attributes_format ();
	_tmp7_ = _tmp6_;
	player_item_reset (_tmp5_, _tmp7_);
	_g_object_unref0 (_tmp7_);
	_g_object_unref0 (_tmp5_);
	_tmp8_ = gee_abstract_list_get ((GeeAbstractList*) self->custom_items, (gint) PLAYER_CONTROLLER_WIDGET_ORDER_TITLE);
	_tmp9_ = (PlayerItem*) _tmp8_;
	title = IS_TITLE_MENUITEM (_tmp9_) ? ((TitleMenuitem*) _tmp9_) : NULL;
	title_menuitem_toggle_active_triangle (title, FALSE);
	_g_object_unref0 (self->mpris_bridge);
	self->mpris_bridge = NULL;
	_g_object_unref0 (title);
}


void player_controller_update_layout (PlayerController* self) {
	gpointer _tmp0_ = NULL;
	PlayerItem* _tmp1_;
	PlaylistsMenuitem* playlists_menuitem;
	gpointer _tmp6_ = NULL;
	PlayerItem* _tmp7_;
	gpointer _tmp8_ = NULL;
	PlayerItem* _tmp9_;
	GeeHashSet* _tmp10_ = NULL;
	GeeHashSet* _tmp11_;
	gboolean _tmp12_;
	gpointer _tmp13_ = NULL;
	PlayerItem* _tmp14_;
	g_return_if_fail (self != NULL);
	_tmp0_ = gee_abstract_list_get ((GeeAbstractList*) self->custom_items, (gint) PLAYER_CONTROLLER_WIDGET_ORDER_PLAYLISTS);
	_tmp1_ = (PlayerItem*) _tmp0_;
	playlists_menuitem = IS_PLAYLISTS_MENUITEM (_tmp1_) ? ((PlaylistsMenuitem*) _tmp1_) : NULL;
	if (self->current_state != PLAYER_CONTROLLER_STATE_CONNECTED) {
		gpointer _tmp2_ = NULL;
		PlayerItem* _tmp3_;
		gpointer _tmp4_ = NULL;
		PlayerItem* _tmp5_;
		_tmp2_ = gee_abstract_list_get ((GeeAbstractList*) self->custom_items, (gint) PLAYER_CONTROLLER_WIDGET_ORDER_TRANSPORT);
		_tmp3_ = (PlayerItem*) _tmp2_;
		dbusmenu_menuitem_property_set_bool ((DbusmenuMenuitem*) _tmp3_, DBUSMENU_MENUITEM_PROP_VISIBLE, FALSE);
		_g_object_unref0 (_tmp3_);
		_tmp4_ = gee_abstract_list_get ((GeeAbstractList*) self->custom_items, (gint) PLAYER_CONTROLLER_WIDGET_ORDER_METADATA);
		_tmp5_ = (PlayerItem*) _tmp4_;
		dbusmenu_menuitem_property_set_bool ((DbusmenuMenuitem*) _tmp5_, DBUSMENU_MENUITEM_PROP_VISIBLE, FALSE);
		_g_object_unref0 (_tmp5_);
		dbusmenu_menuitem_property_set_bool (playlists_menuitem->root_item, DBUSMENU_MENUITEM_PROP_VISIBLE, FALSE);
		_g_object_unref0 (playlists_menuitem);
		return;
	}
	_tmp6_ = gee_abstract_list_get ((GeeAbstractList*) self->custom_items, (gint) PLAYER_CONTROLLER_WIDGET_ORDER_METADATA);
	_tmp7_ = (PlayerItem*) _tmp6_;
	_tmp8_ = gee_abstract_list_get ((GeeAbstractList*) self->custom_items, (gint) PLAYER_CONTROLLER_WIDGET_ORDER_METADATA);
	_tmp9_ = (PlayerItem*) _tmp8_;
	_tmp10_ = metadata_menuitem_attributes_format ();
	_tmp11_ = _tmp10_;
	_tmp12_ = player_item_populated (_tmp9_, _tmp11_);
	dbusmenu_menuitem_property_set_bool ((DbusmenuMenuitem*) _tmp7_, DBUSMENU_MENUITEM_PROP_VISIBLE, _tmp12_);
	_g_object_unref0 (_tmp11_);
	_g_object_unref0 (_tmp9_);
	_g_object_unref0 (_tmp7_);
	_tmp13_ = gee_abstract_list_get ((GeeAbstractList*) self->custom_items, (gint) PLAYER_CONTROLLER_WIDGET_ORDER_TRANSPORT);
	_tmp14_ = (PlayerItem*) _tmp13_;
	dbusmenu_menuitem_property_set_bool ((DbusmenuMenuitem*) _tmp14_, DBUSMENU_MENUITEM_PROP_VISIBLE, TRUE);
	_g_object_unref0 (_tmp14_);
	dbusmenu_menuitem_property_set_bool (playlists_menuitem->root_item, DBUSMENU_MENUITEM_PROP_VISIBLE, *self->use_playlists);
	_g_object_unref0 (playlists_menuitem);
}


static void player_controller_construct_widgets (PlayerController* self) {
	PlayerItem* _tmp0_ = NULL;
	PlayerItem* _tmp1_;
	TitleMenuitem* _tmp2_ = NULL;
	TitleMenuitem* title_menu_item;
	MetadataMenuitem* _tmp3_ = NULL;
	MetadataMenuitem* metadata_item;
	TransportMenuitem* _tmp4_ = NULL;
	TransportMenuitem* transport_item;
	PlaylistsMenuitem* _tmp5_ = NULL;
	PlaylistsMenuitem* playlist_menuitem;
	g_return_if_fail (self != NULL);
	_tmp0_ = player_item_new (DBUSMENU_CLIENT_TYPES_SEPARATOR);
	_tmp1_ = _tmp0_;
	gee_abstract_collection_add ((GeeAbstractCollection*) self->custom_items, _tmp1_);
	_g_object_unref0 (_tmp1_);
	_tmp2_ = title_menuitem_new (self);
	title_menu_item = _tmp2_;
	gee_abstract_collection_add ((GeeAbstractCollection*) self->custom_items, (PlayerItem*) title_menu_item);
	_tmp3_ = metadata_menuitem_new ();
	metadata_item = _tmp3_;
	gee_abstract_collection_add ((GeeAbstractCollection*) self->custom_items, (PlayerItem*) metadata_item);
	_tmp4_ = transport_menuitem_new (self);
	transport_item = _tmp4_;
	gee_abstract_collection_add ((GeeAbstractCollection*) self->custom_items, (PlayerItem*) transport_item);
	_tmp5_ = playlists_menuitem_new (self);
	playlist_menuitem = _tmp5_;
	gee_abstract_collection_add ((GeeAbstractCollection*) self->custom_items, (PlayerItem*) playlist_menuitem);
	{
		GeeArrayList* _tmp6_;
		GeeArrayList* _item_list;
		gint _tmp7_;
		gint _item_size;
		gint _item_index;
		_tmp6_ = _g_object_ref0 (self->custom_items);
		_item_list = _tmp6_;
		_tmp7_ = gee_collection_get_size ((GeeCollection*) _item_list);
		_item_size = _tmp7_;
		_item_index = -1;
		while (TRUE) {
			gpointer _tmp8_ = NULL;
			PlayerItem* item;
			gint _tmp9_;
			_item_index = _item_index + 1;
			if (!(_item_index < _item_size)) {
				break;
			}
			_tmp8_ = gee_abstract_list_get ((GeeAbstractList*) _item_list, _item_index);
			item = (PlayerItem*) _tmp8_;
			_tmp9_ = gee_abstract_list_index_of ((GeeAbstractList*) self->custom_items, item);
			if (_tmp9_ != 4) {
				gint _tmp10_;
				_tmp10_ = gee_abstract_list_index_of ((GeeAbstractList*) self->custom_items, item);
				dbusmenu_menuitem_child_add_position (self->priv->root_menu, (DbusmenuMenuitem*) item, (guint) (self->priv->_menu_offset + _tmp10_));
			} else {
				PlayerItem* _tmp11_;
				PlaylistsMenuitem* _tmp12_;
				PlaylistsMenuitem* playlists_menuitem;
				gint _tmp13_;
				_tmp11_ = item;
				_tmp12_ = _g_object_ref0 (IS_PLAYLISTS_MENUITEM (_tmp11_) ? ((PlaylistsMenuitem*) _tmp11_) : NULL);
				playlists_menuitem = _tmp12_;
				_tmp13_ = gee_abstract_list_index_of ((GeeAbstractList*) self->custom_items, item);
				dbusmenu_menuitem_child_add_position (self->priv->root_menu, playlists_menuitem->root_item, (guint) (self->priv->_menu_offset + _tmp13_));
				_g_object_unref0 (playlists_menuitem);
			}
			_g_object_unref0 (item);
		}
		_g_object_unref0 (_item_list);
	}
	_g_object_unref0 (playlist_menuitem);
	_g_object_unref0 (transport_item);
	_g_object_unref0 (metadata_item);
	_g_object_unref0 (title_menu_item);
}


static void player_controller_determine_state (PlayerController* self) {
	gboolean _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = mpris2_controller_connected (self->mpris_bridge);
	if (_tmp0_ == TRUE) {
		gpointer _tmp1_ = NULL;
		PlayerItem* _tmp2_;
		TitleMenuitem* title;
		player_controller_update_state (self, PLAYER_CONTROLLER_STATE_CONNECTED);
		_tmp1_ = gee_abstract_list_get ((GeeAbstractList*) self->custom_items, (gint) PLAYER_CONTROLLER_WIDGET_ORDER_TITLE);
		_tmp2_ = (PlayerItem*) _tmp1_;
		title = IS_TITLE_MENUITEM (_tmp2_) ? ((TitleMenuitem*) _tmp2_) : NULL;
		title_menuitem_toggle_active_triangle (title, TRUE);
		mpris2_controller_initial_update (self->mpris_bridge);
		_g_object_unref0 (title);
	} else {
		player_controller_update_state (self, PLAYER_CONTROLLER_STATE_DISCONNECTED);
	}
}


const gchar* player_controller_get_dbus_name (PlayerController* self) {
	const gchar* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_dbus_name;
	return result;
}


void player_controller_set_dbus_name (PlayerController* self, const gchar* value) {
	gchar* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_strdup (value);
	_g_free0 (self->priv->_dbus_name);
	self->priv->_dbus_name = _tmp0_;
	g_object_notify ((GObject *) self, "dbus-name");
}


GAppInfo* player_controller_get_app_info (PlayerController* self) {
	GAppInfo* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_app_info;
	return result;
}


void player_controller_set_app_info (PlayerController* self, GAppInfo* value) {
	GAppInfo* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = _g_object_ref0 (value);
	_g_object_unref0 (self->priv->_app_info);
	self->priv->_app_info = _tmp0_;
	g_object_notify ((GObject *) self, "app-info");
}


gint player_controller_get_menu_offset (PlayerController* self) {
	gint result;
	g_return_val_if_fail (self != NULL, 0);
	result = self->priv->_menu_offset;
	return result;
}


void player_controller_set_menu_offset (PlayerController* self, gint value) {
	g_return_if_fail (self != NULL);
	self->priv->_menu_offset = value;
	g_object_notify ((GObject *) self, "menu-offset");
}


const gchar* player_controller_get_icon_name (PlayerController* self) {
	const gchar* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_icon_name;
	return result;
}


void player_controller_set_icon_name (PlayerController* self, const gchar* value) {
	gchar* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = g_strdup (value);
	_g_free0 (self->priv->_icon_name);
	self->priv->_icon_name = _tmp0_;
	g_object_notify ((GObject *) self, "icon-name");
}


static void player_controller_class_init (PlayerControllerClass * klass) {
	player_controller_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (PlayerControllerPrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_player_controller_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_player_controller_set_property;
	G_OBJECT_CLASS (klass)->finalize = player_controller_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), PLAYER_CONTROLLER_DBUS_NAME, g_param_spec_string ("dbus-name", "dbus-name", "dbus-name", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), PLAYER_CONTROLLER_APP_INFO, g_param_spec_object ("app-info", "app-info", "app-info", G_TYPE_APP_INFO, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), PLAYER_CONTROLLER_MENU_OFFSET, g_param_spec_int ("menu-offset", "menu-offset", "menu-offset", G_MININT, G_MAXINT, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), PLAYER_CONTROLLER_ICON_NAME, g_param_spec_string ("icon-name", "icon-name", "icon-name", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void player_controller_instance_init (PlayerController * self) {
	self->priv = PLAYER_CONTROLLER_GET_PRIVATE (self);
	self->current_state = (gint) PLAYER_CONTROLLER_STATE_OFFLINE;
}


static void player_controller_finalize (GObject* obj) {
	PlayerController * self;
	self = PLAYER_CONTROLLER (obj);
	_g_object_unref0 (self->priv->root_menu);
	_g_free0 (self->priv->_dbus_name);
	_g_object_unref0 (self->custom_items);
	_g_object_unref0 (self->mpris_bridge);
	_g_object_unref0 (self->priv->_app_info);
	_g_free0 (self->priv->_icon_name);
	_g_free0 (self->use_playlists);
	G_OBJECT_CLASS (player_controller_parent_class)->finalize (obj);
}


GType player_controller_get_type (void) {
	static volatile gsize player_controller_type_id__volatile = 0;
	if (g_once_init_enter (&player_controller_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (PlayerControllerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) player_controller_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (PlayerController), 0, (GInstanceInitFunc) player_controller_instance_init, NULL };
		GType player_controller_type_id;
		player_controller_type_id = g_type_register_static (G_TYPE_OBJECT, "PlayerController", &g_define_type_info, 0);
		g_once_init_leave (&player_controller_type_id__volatile, player_controller_type_id);
	}
	return player_controller_type_id__volatile;
}


static void _vala_player_controller_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	PlayerController * self;
	self = PLAYER_CONTROLLER (object);
	switch (property_id) {
		case PLAYER_CONTROLLER_DBUS_NAME:
		g_value_set_string (value, player_controller_get_dbus_name (self));
		break;
		case PLAYER_CONTROLLER_APP_INFO:
		g_value_set_object (value, player_controller_get_app_info (self));
		break;
		case PLAYER_CONTROLLER_MENU_OFFSET:
		g_value_set_int (value, player_controller_get_menu_offset (self));
		break;
		case PLAYER_CONTROLLER_ICON_NAME:
		g_value_set_string (value, player_controller_get_icon_name (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_player_controller_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	PlayerController * self;
	self = PLAYER_CONTROLLER (object);
	switch (property_id) {
		case PLAYER_CONTROLLER_DBUS_NAME:
		player_controller_set_dbus_name (self, g_value_get_string (value));
		break;
		case PLAYER_CONTROLLER_APP_INFO:
		player_controller_set_app_info (self, g_value_get_object (value));
		break;
		case PLAYER_CONTROLLER_MENU_OFFSET:
		player_controller_set_menu_offset (self, g_value_get_int (value));
		break;
		case PLAYER_CONTROLLER_ICON_NAME:
		player_controller_set_icon_name (self, g_value_get_string (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



