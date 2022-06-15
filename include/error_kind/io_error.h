#ifndef WINGMANN_ERR_FUSION_ERROR_KIND_IO_ERROR_H
#define WINGMANN_ERR_FUSION_ERROR_KIND_IO_ERROR_H

namespace wingmann::ef::err_kind {

enum class IOError {
	NotFound,
	PermissionDenied,
	ConnectionRefused,
	ConnectionReset,
	HostUnreachable,
	NetworkUnreachable,
	ConnectionAborted,
	NotConnected,
	AddressInUse,
	AddressNotAvailable,
	NetworkDown,
	BrokenPipe,
	AlreadyExists,
	WouldBlock,
	NotADirectory,
	IsADirectory,
	DirectoryNotEmpty,
	ReadOnlyFilesystem,
	FilesystemLoop,
	StaleNetworkFileHandle,
	InvalidInput,
	InvalidData,
	TimedOut,
	WriteZero,
	StorageFull,
	NotSeekable,
	FilesystemQuotaExceeded,
	FileTooLarge,
	ResourceBusy,
	ExecutableFileBusy,
	Deadlock,
	CrossesDevices,
	TooManyLinks,
	InvalidFilename,
	ArgumentListTooLong,
	Interrupted,
	Unsupported,
	UnexpectedEof,
	OutOfMemory,
	Other
};

} // namespace wingmann::ef::err_kind

#endif // WINGMANN_ERR_FUSION_ERROR_KIND_IO_ERROR_H
