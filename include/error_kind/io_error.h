#ifndef WINGMANN_ERR_FUSION_ERROR_KIND_IO_ERROR_H
#define WINGMANN_ERR_FUSION_ERROR_KIND_IO_ERROR_H

namespace wingmann::ef::err_kind {

enum class io_error {
    not_found,
    permission_denied,
    connection_refused,
    connection_reset,
    host_unreachable,
    network_unreachable,
    connection_aborted,
    not_connected,
    address_in_use,
    address_not_available,
    network_down,
    broken_pipe,
    already_exists,
    would_block,
    not_a_directory,
    is_a_directory,
    directory_not_empty,
    read_only_filesystem,
    filesystem_loop,
    stale_network_file_handle,
    invalid_input,
    invalid_data,
    timed_out,
    write_zero,
    storage_full,
    not_seekable,
    filesystem_quota_exceeded,
    file_too_large,
    resource_busy,
    executable_file_busy,
    deadlock,
    crosses_devices,
    too_many_links,
    invalid_filename,
    argument_list_too_long,
    interrupted,
    unsupported,
    unexpected_eof,
    out_of_memory,
    other
};

} // namespace wingmann::ef::err_kind

#endif // WINGMANN_ERR_FUSION_ERROR_KIND_IO_ERROR_H
