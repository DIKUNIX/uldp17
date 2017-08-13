;; choose a directory for backup files
(defvar backup-directory "~/.backups")
(if (not (file-exists-p backup-directory))
    (make-directory backup-directory t))

;; choose configuration for backup files
(setq
 make-backup-files t    ; backup a file the first time it is saved
 backup-directory-alist `((".*" . ,backup-directory)) ; save files in chosen backup folder
 backup-by-copying t    ; copy the current file into backup directory
 version-control t      ; version numbers for backup files
 delete-old-versions t  ; delete unnecessary versions
 kept-old-versions 6    ; oldest versions to keep when a new numbered backup is made (default: 2)
 kept-new-versions 9    ; newest versions to keep when a new numbered backup is made (default: 2)
 auto-save-default t    ; auto-save every buffer that visits a file
 auto-save-timeout 40   ; number of seconds idle time before auto-save (default: 30)
 auto-save-interval 400 ; number of keystrokes between auto-saves (default: 300)
 )
